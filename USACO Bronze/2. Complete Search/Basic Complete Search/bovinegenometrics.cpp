#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	int n, width, ans = 0;
	cin >> n >> width;
	vector<vector<char>> mat(n * 2, vector<char>(width));
	for (auto& row : mat) {
		for (char& x : row) {
			cin >> x;
		}
	}
	for (int j = 0; j < width; ++j) {
		set<char> appear1;
		for (int i = 0; i < n; ++i) {
			appear1.insert(mat[i][j]);
		}
		set<char> appear2;
		for (int i = n; i < n * 2; ++i) {
			appear2.insert(mat[i][j]);
		}
		bool repeat = false;
		for (char c : appear2) {
			if (appear1.count(c)) {
				repeat = true;
				break;
			}
		}
		if (!repeat) ans++;
	}
	cout << ans;
}