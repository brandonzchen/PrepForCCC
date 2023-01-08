#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n, m;
vector <int> x = { 1, -1, 0, 0 };
vector< int> y = { 0, 0, 1, -1 };

vector <vector<int>> grid(600, vector<int>(600));
vector <vector<int>> used(600, vector<int>(600));
vector<pair<int, int>> good;

void floodfill(int val, int yg, int xg) {

	used[yg][xg] = 1;

	for (int i = 0; i < 4; i++) {
		if (0 <= yg + y[i] && y[i] + yg < n && 0 <= xg + x[i] && x[i] + xg < m) {
			if (val >= abs(grid[yg][xg] - grid[yg + y[i]][xg + x[i]]) and !used[yg + y[i]][xg + x[i]]) {
				floodfill(val, yg + y[i], xg + x[i]);
			}
		}
	}
}

bool check() {
	for (int i = 0; i < good.size(); i++) {
		if (!used[good[i].first][good[i].second]) {
			return false;
		}
	}
	return true;
}

int main()
{
	ifstream cin("ccski.in");
	ofstream cout ("ccski.out");
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			if (temp) {
				good.push_back({ i,j });
			}
		}
	}

	int left= 0, right = 10e9 + 1;
	int ans = abs(grid[0][0] - grid[0][1]);

	while (left <= right) {
		int mid = (left + right) / 2;

		for (int i = 0; i < n; i++) {
			fill(used[i].begin(), used[i].end(), 0);
		}

		floodfill(mid, good[0].first, good[0].second);

		if (check()) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}