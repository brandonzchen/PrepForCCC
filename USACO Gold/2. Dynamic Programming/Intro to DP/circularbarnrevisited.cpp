//#include <bits/stdc++.h>
//using namespace std;
//long long solve(vector<long long> cows, int k) { 
//	int n = cows.size();
//	long long cost[n][n]; 
//	for (int i = 0; i < n; i++) {
//		int j = i;
//		int cntr = n;
//		int dist = 0; 
//		while (cntr--) {
//			if (i == j) {
//				cost[i][j] = 0;
//			}
//			else {
//				cost[i][j] = cost[i][(j - 1 + n) % n] + cows[j] * dist;
//			}
//			dist++, j++;
//			if (j == n) {
//				j = 0;
//			}
//		}
//	}
//	long long dp[n][k]; 
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < k; j++) {
//			dp[i][j] = INT_MAX;
//		}
//	}
//	for (int i = 1; i < n; i++) {
//		dp[i][0] = cost[0][i];
//		for (int j = 1; j < k; j++) {
//			for (int l = 0; l < i; l++) {
//				dp[i][j] = min(dp[i][j], dp[l][j - 1] + cost[l + 1][i]);
//			}
//		}
//	}
//	return dp[n - 1][k - 1];
//}
//int main() {
//	ifstream cin ("cbarn2.in");
//	ofstream cout("cbarn2.out");
//	int n, k;
//	cin >> n >> k;
//	vector<long long> cows(n);
//	for (int i = 0; i < n; i++) {
//		cin >> cows[i];
//	}
//	long long myMin = INT_MAX;
//	for (int i = 0; i < n; i++) {
//		rotate(cows.begin(), cows.begin() + 1, cows.end());
//		myMin = min(solve(cows, k), myMin);
//	}
//	cout << myMin << endl;
//}

#include <bits/stdc++.h>
using namespace std;

long long N, K, M;
const int myINF = 1e9;

int main() {
	//ifstream cin("cbarn2.in");
	//ofstream cout ("cbarn2.out");

	cin >> N >> K;
	vector<long long> cows(N);

	for (int i = 0; i < N; i++) {
		cin >> cows[i];
	}
	long long ans = INT_MAX;

	//rotate barn and avoid circular problems
	for (int rr = 0; rr < N; rr++) {
		vector<long long> currcows = cows;
		rotate(currcows.begin(), currcows.begin() + rr, currcows.end());
		vector<vector<long long>> dp(K + 1, vector<long long>(N, myINF));
		dp[1][0] = 0;

		for (int ii = 1; ii < N; ii++) {
			dp[1][ii] = dp[1][ii - 1] + ii * currcows[ii];
		}
		//one based, start at row two
		for (int i = 2; i < K + 1; i++) {
			for (int j = 1; j < N; j++) {
				//i - maximum number of doors opened
				//j - location covered from 1~j
				dp[i][j] = dp[i - 1][j];

				long long s2 = 0, s1 = 0;
				//check other possible door openings
				// K - last door opened
				// evaluate all possible last opened door location from i+ 1 to j
				for (int k = j; k >= 0; k--) {
					s2 += s1;
					s1 += currcows[k];
					dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + s2);
					//optimization, unneeded
					/*if (s2>dp[i][j]){
						break;
					}*/
				}
			}

		}

		ans = min(ans, dp[K][N - 1]);
	}
	cout << ans;
}