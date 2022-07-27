#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e9 + 7;

int dp[10000001], n, x, coins[100];

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	fill(dp, dp + x + 1, mxn);
	dp[0] = 0;
	for (int i = 1; i <= x; i++) {
		for (int c = 0; c < n; c++) {
			if (i - coins[c] >= 0) {
				if (dp[i - coins[c]] != mxn) {
					dp[i] = min(dp[i], dp[i - coins[c]] + 1);
				}
			}
		}
	}
	dp[x] == mxn ? cout << -1 : cout << dp[x];
}