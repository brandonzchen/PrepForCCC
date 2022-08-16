#include <bits/stdc++.h>
using namespace std;

void addedge(int x, int y, vector<vector<int>>& adj) {
	adj[x].push_back(y);
	adj[y].push_back(x);
}

void bfs()

int main() {
	int nodes;
	cin >> nodes;
	vector<vector<int>> tree(nodes + 1, vector<int>());
	for (int i = 0; i < nodes - 1; i++) {
		int first, second;
		cin >> first >> second;
		addedge(first, second, tree);
	}
	cout << "Hello";

	
}
