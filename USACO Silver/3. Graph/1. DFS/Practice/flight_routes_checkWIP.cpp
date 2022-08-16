//#include <bits/stdc++.h>
//using namespace std;
//using pi = pair<int, int>;
//
//vector<pi>connectedited;
//vector<pi>needsconnectedit;
//vector<pi>flightlist;
//
//int main() {
//	ifstream fin("USACO Silver/3. Graph/1. DFS/Practice/flight_routes_checktest.txt");
//	int cities, flights; fin >> cities >> flights;
//	for (int i = 1; i <= cities; i++) {
//		for (int j = 1; j <= cities; j++) {
//			if (i != j) {
//				pi temp;
//				temp = make_pair(i, j);
//				needsconnectedit.push_back(temp);
//			}
//		}
//	}
//	for (int k = 0; k < flights; k++) {
//		int start, end; fin >> start >> end;
//		pi temp1;
//		temp1 = make_pair(start, end);
//		flightlist.push_back(temp1);
//	}
//
//	for (auto current : flightlist) {
//		if (count(connectedited.begin(), connectedited.end(), current)) {
//			continue;
//		}
//		else {
//			connectedited.push_back(current);
//			stack<pi>dfs;
//			dfs.push(current);
//			while (dfs.size() != 0) {
//				pi node = dfs.top();
//				dfs.pop();
//				for (int l = 0; l < flights; l++) {
//					if (flightlist[l].first == node.second) {
//						pi cnt;
//						cnt = make_pair(current.first, flightlist[l].second);
//						
//						if (count(connectedited.begin(), connectedited.end(), cnt) || cnt.first == cnt.second) continue;
//						else {
//							connectedited.push_back(cnt);
//							dfs.push(cnt);
//						}
//					}
//				}
//
//			}
//		}
//	}
//	if (connectedited.size() != needsconnectedit.size()) {
//		cout << "NO" << endl;
//		int nsize = needsconnectedit.size();
//		for (int i = 0; i < nsize; i++) {
//			if (count(connectedited.begin(), connectedited.end(), needsconnectedit[i])) continue;
//			else {
//				cout << needsconnectedit[i].first << " " << needsconnectedit[i].second;
//				break;
//			}
//		}
//	}
//	else cout << "YES" << endl;
//
//
//}

//#include <bits/stdc++.h> // see C++ Tips & Tricks
//using namespace std;
//
//using ll = long long;
//
//using vi = vector<int>;
//#define pb push_back
//#define rsz resize
//#define all(x) begin(x), end(x)
//#define sz(x) (int)(x).size()
//
//using pi = pair<int, int>;
//#define f first
//#define s second
//#define mp make_pair
//
//void setIO(string name = "") { // name is nonempty for USACO file I/O
//	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
//	// alternatively, cin.tie(0)->sync_with_stdio(0);
//	if (sz(name)) {
//		freopen((name + ".in").c_str(), "r", stdin); // see Input & Output
//		freopen((name + ".out").c_str(), "w", stdout);
//	}
//}
//
//vi adj[100005][2]; bool vis[100005];
//
//void dfs(int v, int x) {
//	vis[v] = true;
//	for (int to : adj[v][x]) {
//		if (!vis[to]) {
//			dfs(to, x);
//		}
//	}
//}
//
//int main() {
//	setIO();
//	int n, m; cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		int u, v; cin >> u >> v;
//		u--, v--;
//		adj[u][0].pb(v);
//		adj[v][1].pb(u);
//	} 
//	dfs(0, 0);
//	for (int i = 0; i < n; i++) {
//		if (!vis[i]) {
//			cout << "NO" << '\n';
//			cout << 1 << " " << i + 1 << '\n';
//			return 0;
//		}
//	}
//	memset(vis, false, sizeof(vis)); //fill vis with false
//	dfs(0, 1);
//	for (int i = 0; i < n; i++) {
//		if (!vis[i]) {
//			cout << "NO" << '\n';
//			cout << i + 1 << " " << 1 << '\n';
//			return 0;
//		}
//	}
//	cout << "YES" << '\n';
//}


#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vi adjacent[100005][2]; bool vis[100005];

void dfs(int a, int b) {
	vis[a] = true;
	for (int cur : adjacent[a][b]) {
		if (!vis[cur]) {
			dfs(cur, b);
		}
	}
}

int main() {
	int cities; int flightnum;
	cin >> cities >> flightnum;
	for (int i = 0; i < flightnum; i++) {
		int start, finish;
		cin >> start >> finish;
		start--;
		finish--;
		adjacent[start][0].push_back(finish);
		adjacent[finish][1].push_back(start);
	}
	dfs(0, 0);
	for (int i = 0; i < cities; i++) {
		if (!vis[i]) {
			cout << "NO" << endl;
			cout << 1 << " " << i + 1;
			return 0;
		}
	}
	memset(vis, false, sizeof(vis));
	dfs(0, 1);
	for (int i = 0; i < cities; i++) {
		if (!vis[i]) {
			cout << "NO" << endl;
			cout << 1 << " " << i + 1;
			return 0;
		}
	}
	cout << "YES";

}