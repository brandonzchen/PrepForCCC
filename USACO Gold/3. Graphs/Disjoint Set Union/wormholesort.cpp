#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5;

vector<pair<int, int>> g[MX];
vector<int> ar(MX), component(MX);
int n, m;

void dfs(int v, int label, int minW) {
	component[v] = label;

	for (auto x : g[v]) {
		if (x.second < minW || component[x.first] != -1) continue;
		dfs(x.first, label, minW);
	}
}

bool ok(int minW) {
	fill(component.begin(), component.end(), -1);
	int label = -1;

	for (int i = 0; i < n; i++) {
		if (component[i] != -1) continue;
		dfs(i, ++label, minW);
	}

	for (int i = 0; i < n; i++) {
		if (component[i] != component[ar[i]]) return false;
	}

	return true;
}

int main() {
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i]--;
	}

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
	}

	int sol = -1;
	int lo = 1, hi = 1e9 + 1;
	int top = hi;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;

		if (ok(mid)) {
			sol = max(sol, mid);
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	cout << (sol == top ? -1 : sol) << '\n';
}