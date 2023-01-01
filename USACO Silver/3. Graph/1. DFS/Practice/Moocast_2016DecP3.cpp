#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(vector<vector<int>> graph, int node, vector<bool>& visited, int& len) {
	visited[node] = true;
	len++;
	for (int i : graph[node]) {
		if (visited[i]) continue;
		dfs(graph, i, visited, len);
	}
}

int main() {
	/*ifstream fin("USACOProblems/Silver/Practice Problems/2016DecP3test.txt");*/
	ifstream cin("moocast.in");
	ofstream cout("moocast.out");
	
	int n; cin >> n;
	vector<vector<int>> cows(n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cows[i] = vector<int>{ a,b,c };
	}

	vector<vector<int>> graph(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dists = sqrt(pow(abs(cows[i][0] - cows[j][0]), 2) + pow(abs(cows[i][1] - cows[j][1]), 2));
			if (dists <= cows[i][2]) graph[i].push_back(j);
			if (dists <= cows[j][2]) graph[j].push_back(i);
		}
	}

	for (int i = 0; i < n; i++) {
		vector<bool> visited(n, false);
		int len = 0;
		dfs(graph, i, visited, len);
		ans = max(ans, len);
	}

	cout << ans;

	return 0;
}