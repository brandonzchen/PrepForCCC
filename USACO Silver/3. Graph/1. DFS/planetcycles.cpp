#include <bits/stdc++.h>
using namespace std;

int n;
int planets[200000];
vector<vector<int> > adj(200000);
int connected[200000];

void dfs(int u, int t)
{
	if (connected[u] > 0) return;
	connected[u] = t;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		dfs(v, t + 1);
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> planets[i];
		planets[i]--;
		adj[i].push_back(planets[i]);
		adj[planets[i]].push_back(i);
	}

	for (int i = 0; i < n; i++) {
		if (connected[i] == 0) {
			vector<int> cycle;
			int t = i, h = i;
			t = planets[t]; h = planets[planets[h]];
			while (t != h) {
				t = planets[t];
				h = planets[planets[h]];
			}

			t = i;
			while (t != h) {
				t = planets[t];
				h = planets[h];
			}

			cycle.push_back(t);
			t = planets[t];
			while (t != h) {
				cycle.push_back(t);
				t = planets[t];
			}

			for (int j = 0; j < cycle.size(); j++) {
				connected[cycle[i]] = cycle.size();
			}
			for (auto u : cycle) {
				for (int i = 0; i < adj[u].size(); i++) {
					int v = adj[u][i];
					dfs(v, cycle.size() + 1);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << connected[i] << " ";
	}
}