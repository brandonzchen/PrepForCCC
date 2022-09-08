#include <bits/stdc++.h>
using namespace std;
long long solve(vector<long long> cows, int k) { 
	int n = cows.size();
	long long cost[n][n]; 
	for (int i = 0; i < n; i++) {
		int j = i;
		int cntr = n;
		int dist = 0; 
		while (cntr--) {
			if (i == j) {
				cost[i][j] = 0;
			}
			else {
				cost[i][j] = cost[i][(j - 1 + n) % n] + cows[j] * dist;
			}
			dist++, j++;
			if (j == n) {
				j = 0;
			}
		}
	}
	long long dp[n][k]; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			dp[i][j] = INT_MAX;
		}
	}
	for (int i = 1; i < n; i++) {
		dp[i][0] = cost[0][i];
		for (int j = 1; j < k; j++) {
			for (int l = 0; l < i; l++) {
				dp[i][j] = min(dp[i][j], dp[l][j - 1] + cost[l + 1][i]);
			}
		}
	}
	return dp[n - 1][k - 1];
}
int main() {
	freopen("cbarn2.in", "r", stdin);
	freopen("cbarn2.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<long long> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i];
	}
	long long myMin = INT_MAX;
	for (int i = 0; i < n; i++) {
		rotate(cows.begin(), cows.begin() + 1, cows.end());
		myMin = min(solve(cows, k), myMin);
	}
	cout << myMin << endl;
}