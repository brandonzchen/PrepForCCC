#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

vector<pi>visited;
vector<pi>needsvisit;
vector<pi>flightlist;

int main() {
	ifstream fin("USACO Silver/3. Graph/1. DFS/Practice/flight_routes_checktest.txt");
	int cities, flights; fin >> cities >> flights;
	for (int i = 1; i <= cities; i++) {
		for (int j = 1; j <= cities; j++) {
			if (i != j) {
				pi temp;
				temp = make_pair(i, j);
				needsvisit.push_back(temp);
			}
		}
	}
	for (int k = 0; k < flights; k++) {
		int start, end; fin >> start >> end;
		pi temp1;
		temp1 = make_pair(start, end);
		flightlist.push_back(temp1);
	}

	for (auto current : flightlist) {
		if (count(visited.begin(), visited.end(), current)) {
			continue;
		}
		else {
			visited.push_back(current);
			stack<pi>dfs;
			dfs.push(current);
			while (dfs.size() != 0) {
				pi node = dfs.top();
				dfs.pop();
				for (int l = 0; l < flights; l++) {
					if (flightlist[l].first == node.second) {
						pi cnt;
						cnt = make_pair(current.first, flightlist[l].second);
						
						if (count(visited.begin(), visited.end(), cnt) || cnt.first == cnt.second) continue;
						else {
							visited.push_back(cnt);
							dfs.push(cnt);
						}
					}
				}

			}
		}
	}
	if (visited.size() != needsvisit.size()) {
		cout << "NO" << endl;
		for (int i = 0; i < needsvisit.size(); i++) {
			if (count(visited.begin(), visited.end(), needsvisit[i])) continue;
			else {
				cout << needsvisit[i].first << " " << needsvisit[i].second;
				break;
			}
		}
	}
	else cout << "YES" << endl;


}