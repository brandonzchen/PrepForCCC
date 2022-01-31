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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;




vi grid[100005][2]; bool connected[100005];

void dfs(int v, int x) {
	connected[v] = true;
	for (int to : grid[v][x]) {
		if (!connected[to]) {
			dfs(to, x);
		}
	}
}

int main() {
	int cities, flights; cin >> cities >> flights;
	for (int i = 0; i < flights; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		grid[u][0].push_back(v);
		grid[v][1].push_back(u);
	}
	dfs(0, 0);
	for (int i = 0; i < cities; i++) {
		if (!connected[i]) {
			cout << "NO" << endl;
			cout << 1 << " " << i + 1 << endl;
			return 0;
		}
	}
	memset(connected, false, sizeof(connected));
	dfs(0, 1);
	for (int i = 0; i < cities; i++) {
		if (!connected[i]) {
			cout << "NO" << endl;
			cout << i + 1 << " " << 1 << endl;;
			return 0;
		}
	}
	cout << "YES" << endl;
}