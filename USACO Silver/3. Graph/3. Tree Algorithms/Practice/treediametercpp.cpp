//#include <bits/stdc++.h>
//using namespace std;
//
//void addedge(int x, int y, vector<vector<int>>& adj) {
//	adj[x].push_back(y);
//	adj[y].push_back(x);
//}
//
//void bfs()
//
//int main() {
//	int nodes;
//	cin >> nodes;
//	vector<vector<int>> tree(nodes + 1, vector<int>());
//	for (int i = 0; i < nodes - 1; i++) {
//		int first, second;
//		cin >> first >> second;
//		addedge(first, second, tree);
//	}
//	cout << "Hello";
//
//	
//}

#include <bits/stdc++.h>

using namespace std;

const int mxn = 2e5 + 1;
int n, dis = 0, end1;
vector<int> adj[mxn];

void dfs(int node, int pre, int depth) {
	for (int i : adj[node])
		if (i != pre)
			dfs(i, node, depth + 1);
	if (depth > dis) dis = depth, end1 = node;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, 0);
	dfs(end1, 0, 0);
	cout << dis << "\n";
}

