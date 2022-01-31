#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
	ll numcases; cin >> numcases;
	for (ll i = 0; i < numcases; i++) {
		ll start, finish; cin >> start >> finish;
		ll ans = 0;
		ll index = 0;
		vector<vector<ll>>bfs;
		vector<ll>first = { start };
		bfs.push_back(first);
		while (start != finish) {
			vector <ll> current = bfs[index];
			vector<ll> next; 
			for (ll j = 0; j < current.size(); j++) {
				ll node = current[j];
				next.push_back(node * 2);
				next.push_back(node + 1);
				if (node % 2 == 0) {
					next.push_back(node / 2);
				}
				if (node == finish) {
					start = node;
					ans = bfs.size();
					break;
				}
			}
			bfs.push_back(next);
			if (start == finish) {
				break;
			}
			index++;
		}
		cout << ans;

	}

}
