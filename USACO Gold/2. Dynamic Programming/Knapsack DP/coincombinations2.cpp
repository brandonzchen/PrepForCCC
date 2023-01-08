#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
//int main() {
//	//Take inputs
//	int n, k;
//	cin >> n >> k;
//	vector<int> coins(n);
//	for (int i = 0; i < n; i++)
//		cin >> coins[i];
//
//	sort(coins.begin(), coins.end());
//	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
//	dp[0][0] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= k; j++) {
//			dp[i][j] = dp[i - 1][j];
//			if (j - coins[i - 1] >= 0 && dp[i][j - coins[i - 1]] != 0) {
//				dp[i][j] = (dp[i][j] + dp[i][j - coins[i - 1]]) % int(1e9 + 7);
//			}
//		}
//	}
//
//
//	cout << dp[n][k];
//
//	return 0;
//}

ll dp[1000001];

const int MOD = (int)1e9 + 7;

int main() {
	int n, x; cin >> n >> x;
	vi coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int weight = 0; weight <= x; weight++) {
			if (weight - coins[i - 1] >= 0) {  // prevent out of bounds cases
				dp[weight] += dp[weight - coins[i - 1]];
				dp[weight] %= MOD;
			}
		}
	}
	cout << dp[x];
}
