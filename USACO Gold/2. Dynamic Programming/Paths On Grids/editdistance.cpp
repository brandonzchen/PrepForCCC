#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[5001][5001];

int main() {

	cin >> s1 >> s2;
	for (int i = 1; i <= (int)s1.size(); i++) {
		dp[i][0] = i;
	}
	for (int i = 1; i <= (int)s2.size(); i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= (int)s1.size(); i++) {
		for (int j = 1; j <= (int)s2.size(); j++) {
			int cost = 1;
			if (s1[i - 1] == s2[j - 1]) cost = 0;
			dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost));
		}
	}
	cout << dp[s1.size()][s2.size()];
}