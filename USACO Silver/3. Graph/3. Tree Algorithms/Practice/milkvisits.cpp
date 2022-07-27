#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5;
int n, m, comp[mxn + 1];
string cows;
vector<int> adj[mxn + 1];
bool vis[mxn + 1];

void dfs(int node, int l) {
	vis[node] = 1;
	comp[node] = l;
	for (int i : adj[node])
		if (!vis[i] && cows[i - 1] == cows[node - 1])
			dfs(i, l);
}

int main() {
	
	ifstream cin("milkvisits.in");
	ofstream cout("milkvisits.out");
	cin >> n >> m >> cows;
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int label = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i, ++label);

	for (int i = 0; i < m; i++) {
		int node1, node2;
		char cow;
		cin >> node1 >> node2 >> cow;
		if (comp[node1] != comp[node2] || cows[node1 - 1] == cow)
			cout << 1;
		else cout << 0;
	}
	cout << "\n";
}