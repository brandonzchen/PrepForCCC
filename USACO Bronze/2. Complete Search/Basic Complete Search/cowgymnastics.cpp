#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	int k, n, ans = 0; cin >> k >> n;
	int cows[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cows[i][j] = 0;
	}

	for (int m = 0; m < n; m++) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				int indexi = find(v.begin(), v.end(), i + 1) - v.begin();
				int indexj = find(v.begin(), v.end(), j + 1) - v.begin();

				if (indexi < indexj) {
					cows[i][j]++;
				}
			}

		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cows[i][j] == k) ans++;
		}

	}
	cout << ans << endl;


	return 0;
}
