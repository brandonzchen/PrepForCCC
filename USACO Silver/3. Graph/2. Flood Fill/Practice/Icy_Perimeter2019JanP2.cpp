#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;

int main() {
	/*ifstream fin("USACO Silver/3. Graph/2. Flood Fill/Practice/2019JanP2test.txt");*/
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
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

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1005;

char grid[MAXN][MAXN]; // the grid itself
int n;
bool visited[MAXN][MAXN]; // keeps track of which nodes have been visited
ll currA = 0; // keeps track of the current area of the current blob of ice cream
ll currP = 0; // keeps track of the current perimeter of the blob of ice cream
ll area = 0;
ll perimeter = 0;


void floodfill(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) {
		currP++;
		return; // if outside grid
	}
	if (visited[r][c]) return; // already visited this square
	if (grid[r][c] == '.') {
		currP++;
		return;
	}
	visited[r][c] = true; // mark current square as visited
	if (grid[r][c] == '#') {
		currA++;
	}
	// recursively call floodfill for neighboring squares
	floodfill(r, c + 1);
	floodfill(r, c - 1);
	floodfill(r - 1, c);
	floodfill(r + 1, c);
}

int main() {
	ifstream fin("perimeter.in");
	ofstream fout("perimeter.out");
	fin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin>> grid[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && grid[i][j] == '#') {
				floodfill(i, j);
				if (area == currA) {
					perimeter = min(perimeter, currP);
				}
				else if (currA > area) {
					area = currA;
					perimeter = currP;
				}
				currA = currP = 0;
			}
		}
	}
	cout << area << " " << perimeter << endl;
	return 0;
}