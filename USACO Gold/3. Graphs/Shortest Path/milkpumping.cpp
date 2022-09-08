#include <bits/stdc++.h>
using namespace std;
vector<int> dist;
vector<vector<pair<pair<int, int>, int>>> graph;
int n;
void dijkstra(long long limit) {
	for (int i = 0; i < n; i++)dist[i] = -1;
	dist[0] = 0; queue<pair<int, int>> q; 
	q.push({ 0, 0 });
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (auto x : graph[cur.second]) {
			if (x.second < limit)continue;
			pair<int, int> u = x.first;
			int curDist = u.second + dist[cur.second];
			if (curDist < dist[u.first] || dist[u.first] == -1) {
				dist[u.first] = curDist;
				q.push({ -1 * curDist, u.first });
			}
		}
	}
}
int main() {
	freopen("pump.in", "r", stdin);
	freopen("pump.out", "w", stdout);
	int m; cin >> n >> m;
	dist.resize(n); graph.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d; a--; b--;
		graph[a].push_back({ {b, c}, d });
		graph[b].push_back({ {a, c}, d });
	}
	long long ret = -1;
	for (int i = 1; i < 1010; i++) {
		dijkstra(i);
		long long cur = i * 1e6;
		if (dist[n - 1] == -1)continue;
		cur /= (dist[n - 1]);
		if (ret == -1 || cur > ret) {
			ret = cur;
		}
	}
	cout << ret << endl;
}