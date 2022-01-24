#include <bits/stdc++.h>

using namespace std;

const int maximum = 1e5 + 10;

int N, M;
vector<pair<int, int>> adj[maximum];
int color[maximum];
bool bad = 0;

void dfs(int x, bool y) {
	if (color[x]) {
		if (color[x] != y + 1)
			bad = 1;
		return;
	}
	color[x] = y + 1;
	for (pair<int, int>& v : adj[x]) {
		if (v.second == 1)
			dfs(v.first, y);
		else
			dfs(v.first, !y);
	}
}


int main(){
	ifstream fin("USACOProblems/Silver/Practice Problems/2019FebP3test.txt");
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);

	fin >> N >> M;

	while (M--) {
		int a, b; char c;
		fin >> c >> a >> b;
		--a, --b;
		int d = (c == 'S' ? 1 : 0);
		adj[a].push_back({ b, d });
		adj[b].push_back({ a, d });
	}

	int connect = 0;
	for (int i = 0; i < N; i++) {
		if (!color[i]) {
			connect++; 
			dfs(i, 0); 
			if (bad) {
				cout << 0 << endl;
				break;
			}
		}
	}


	cout << 1;
	
	while (connect--) cout << 0;
	cout << endl;
}

