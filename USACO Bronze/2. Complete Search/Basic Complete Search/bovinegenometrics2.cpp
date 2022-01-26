#include <bits/stdc++.h>
using namespace std;

const int mxN = 500;
int n, m, ans;
string genes[2 * mxN];

int num(char c) {
	if (c == 'A')
		return 0;
	if (c == 'T')
		return 1;
	if (c == 'C')
		return 2;
	return 3;
}

int main() {
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < 2 * n; ++i)
		cin >> genes[i];
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			for (int k = j + 1; k < m; ++k) {
				bool a[4][4][4], valid = 1;
				memset(a, 0, 64);
				for (int p = 0; p < n; ++p)
					a[num(genes[p][i])][num(genes[p][j])][num(genes[p][k])] = 1;
				for (int p = n; p < 2 * n; ++p) {
					if (a[num(genes[p][i])][num(genes[p][j])][num(genes[p][k])]) {
						valid = 0;
						break;
					}
				}
				ans += valid;
			}
		}
	}
	cout << ans;
}