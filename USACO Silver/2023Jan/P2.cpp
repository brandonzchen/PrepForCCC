#include <bits/stdc++.h>
using namespace std;

char grid[1502][1502];
int gridsum[1502][1502];
int column[1502];
int row[1502];

int main() {

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
		cin >> column[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> row[i];
	}
	int totalcost = 0;
	for (int j = 1; j <= n; j++) {
		int cost = row[j];
		int tempcount = 0;
		stack<pair<int, int>>dfs;
		if (grid[n][j] == 'D') {
			pair<int, int>temp{ n, j };
			dfs.push(temp);
			tempcount++;
			gridsum[n][j] = cost;
		}
		while (dfs.size() != 0) {
			pair<int, int> current = dfs.top();
			dfs.pop();
			if (current.first - 1 > 0 && grid[current.first - 1][current.second] == 'D') {
				pair<int, int>temp{ current.first - 1, current.second };
				dfs.push(temp);
				gridsum[current.first - 1][current.second] = cost;
				tempcount++;
			}
			if (current.second - 1 > 0 && grid[current.first][current.second - 1] == 'R') {
				pair<int, int>temp{ current.first, current.second - 1 };
				dfs.push(temp);
				gridsum[current.first][current.second - 1] = cost;
				tempcount++;
			}
		}
		totalcost += tempcount * cost;
	}
	for (int j = 1; j <= n; j++) {
		int cost = column[j];
		int tempcount = 0;
		stack<pair<int, int>>dfs;
		if (grid[j][n] == 'R') {
			pair<int, int>temp{ j, n };
			dfs.push(temp);
			tempcount++;
			gridsum[j][n] = cost;
		}
		while (dfs.size() != 0) {
			pair<int, int> current = dfs.top();
			dfs.pop();
			if (current.first - 1 > 0 && grid[current.first - 1][current.second] == 'D') {
				pair<int, int>temp{ current.first - 1, current.second };
				dfs.push(temp);
				tempcount++;
				gridsum[current.first - 1][current.second] = cost;
			}
			if (current.second - 1 > 0 && grid[current.first][current.second - 1] == 'R') {
				pair<int, int>temp{ current.first, current.second - 1 };
				dfs.push(temp);
				gridsum[current.first][current.second - 1] = cost;
				tempcount++;
			}
		}
		totalcost += tempcount * cost;
	}
	cout << totalcost << endl;
	int testcases; cin >> testcases;
	for (int k = 0; k < testcases; k++) {
		int x, y; cin >> x >> y;
		int numberschanged = 1;
		int costbefore = gridsum[x][y];
		int costafter = 0;
		if (grid[x][y] == 'R') {
			if (x + 1 <= n) {
				costafter = gridsum[x + 1][y];
				gridsum[x][y] = gridsum[x + 1][y];
			}
			else {
				costafter = row[y];
				gridsum[x][y] = row[y];
			}
			grid[x][y] = 'D';

		}
		else if (grid[x][y] == 'D') {
			if (y + 1 <= n) {
				costafter = gridsum[x][y + 1];
				gridsum[x][y] = gridsum[x][y + 1];
			}
			else {
				costafter = column[x];
				gridsum[x][y] = column[x];
			}
			grid[x][y] = 'R';
		}
		stack<pair<int, int>>dfs;
		pair<int, int>temp{ x, y };
		dfs.push(temp);
		while (dfs.size() != 0) {
			pair<int, int> current = dfs.top();
			dfs.pop();
			if (current.first - 1 > 0 && grid[current.first - 1][current.second] == 'D') {
				pair<int, int>temp{ current.first - 1, current.second };
				dfs.push(temp);
				numberschanged++;
				gridsum[current.first - 1][current.second] = costafter;
			}
			if (current.second - 1 > 0 && grid[current.first][current.second - 1] == 'R') {
				pair<int, int>temp{ current.first, current.second - 1 };
				dfs.push(temp);
				gridsum[current.first][current.second - 1] = costafter;
				numberschanged++;
			}
		}
		totalcost -= costbefore * numberschanged;
		totalcost += costafter * numberschanged;
		cout << totalcost << endl;
	}
	
}