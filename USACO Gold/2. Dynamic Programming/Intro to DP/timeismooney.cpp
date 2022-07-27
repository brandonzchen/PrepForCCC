#include <bits/stdc++.h>
using namespace std;
int N, M, C, a, b, ans, m[1001], dp[1001][1001];
vector<int> adj[1001];
int main()
{
	ifstream cin("time.in");
	ofstream cout("time.out");

	cin >> N >> M >> C;
	for (int i = 1; i <= N; i++) cin >> m[i];

	while (M--)
	{
		cin >> a >> b;
		adj[a].push_back(b);
	}
	memset(dp, -1, sizeof(dp)), dp[0][1] = 0;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto u : adj[j]) if (dp[i][j] >= 0) {
				dp[i + 1][u] = max(dp[i + 1][u], dp[i][j] + m[u]);
			}
		}
	}
	for (int i = 0; i <= 1000; i++) {
		ans = max(ans, dp[i][1] - C * i * i);
	}
	cout << ans;
}