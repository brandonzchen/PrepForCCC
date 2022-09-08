#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;

int main() {
	/*ifstream fin("USACO Silver/3. Graph/2. Flood Fill/Practice/2019JanP2test.txt");*/
	ifstream cin("perimeter.in");
	ofstream cout("perimeter.out");
	int size;cin >> size;
	vi top(size + 2, 0);
	vector<vi>grid;
	grid.push_back(top); 
	for (int i = 0; i < size; i++) {
		vi row = {0};
		for (int j = 0; j < size; j++) {
			char temp; cin >> temp;
			if (temp == '.') row.push_back(0);
			if (temp == '#') row.push_back(1);
		}
		row.push_back(0);
		grid.push_back(row);
	}
	grid.push_back(top);
	int  maxperi = 0;
	int maxarea = 0;
	for (int i = 0; i < size + 2; i++) {
		for (int j = 0; j < size + 2; j++) {
			if (grid[i][j] == 0) continue;
			if (grid[i][j] == 1) {
				int area = 0, peri = 0;
				stack<pi>blob;
				pi temp;
				temp = make_pair(i, j);
				blob.push(temp);
				while (blob.size() != 0) {
					pi current = blob.top();
					blob.pop();
					area++;
					if (grid[current.first + 1][current.second] == 0) peri++;
					else if (grid[current.first + 1][current.second] == 1) {
						pi temp1 = { current.first + 1, current.second };
						blob.push(temp1);
						grid[current.first + 1][current.second] = 2;
					}
					if (grid[current.first - 1][current.second] == 0) peri++;
					else if (grid[current.first - 1][current.second] == 1) {
						pi temp1 = { current.first - 1, current.second };
						blob.push(temp1);
						grid[current.first - 1][current.second] = 2;
					}
					if (grid[current.first][current.second + 1] == 0) peri++;
					else if (grid[current.first][current.second + 1] == 1) {
						pi temp1 = { current.first, current.second + 1 };
						blob.push(temp1); 
						grid[current.first][current.second + 1] = 2;
					}
					if (grid[current.first][current.second - 1] == 0) peri++;
					else if (grid[current.first][current.second - 1] == 1) {
						pi temp1 = { current.first, current.second - 1 };
						blob.push(temp1);
						grid[current.first][current.second - 1] = 2;
					}
					grid[i][j] = 2;


				}
				if (maxarea == area) {
					maxperi = peri;
				}
				else {
					maxarea = max(maxarea, area);
					maxperi = max(maxperi, peri);
				}
					

			}
		}
	}
	cout << maxarea << " " << maxperi;
}

