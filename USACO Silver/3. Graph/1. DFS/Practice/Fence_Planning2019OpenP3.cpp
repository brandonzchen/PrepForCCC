#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> cows(100000);
vector<int> adj[100000];
bool visited[100000];

int minX, minY, maxX, maxY;

void dfs(int node) {
	if (visited[node]) {
		return;
	}
	minX = min(cows[node].first, minX),
		maxX = max(cows[node].first, maxX),
		minY = min(cows[node].second, minY),
		maxY = max(cows[node].second, maxY);
	visited[node] = true;
	for (int connected : adj[node]) {
		dfs(connected);
	}
}

int main() {
	//ifstream fin("USACOProblems/Silver/Practice Problems/2019OpenP3test.txt");
	ifstream fin("fenceplan.in");
	ofstream fout("fenceplan.out");

	int n, m; fin >> n >> m;

	for (int i = 0; i < n; i++) {
		fin >> cows[i].first >> cows[i].second;
	}
	for (int i = 0; i < m; i++) {
		int a, b; fin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int perimeter = 400000000;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			minX = cows[i].first,
				maxX = cows[i].first,
				minY = cows[i].second,
				maxY = cows[i].second;
			dfs(i);
			perimeter = min(perimeter, 2 * (maxX - minX) + 2 * (maxY - minY));
		}
	}
	fout << perimeter << endl;
}