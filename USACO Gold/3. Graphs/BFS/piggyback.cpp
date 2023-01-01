#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> Q;
vector<int> adj[50000];
vector<vector<int>> dis(3, vector<int>(50000, 1e9));

void bfs(int w, int s)
{
	dis[w][s] = 0;
	queue<int> Q; Q.push(s);
	while (!Q.empty()) {
		int s = Q.front(); Q.pop();
		for (auto u : adj[s])
			if (dis[w][u] == 1e9)
				dis[w][u] = dis[w][s] + 1, Q.push(u);
	}
}

int main()
{
	int b, e, p, n, m;
	ifstream cin("piggyback.in");
	ofstream cout("piggyback.out");
	cin >> b >> e >> p >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	bfs(0, 1), bfs(1, 2), bfs(2, n);
	int ans = 1e9;
	for (int i = 1; i <= n; i++)
		if (dis[0][i] != 1e9 and dis[1][i] != 1e9)
			ans = min(ans, dis[0][i] * b + dis[1][i] * e + dis[2][i] * p);
	cout << ans;
}