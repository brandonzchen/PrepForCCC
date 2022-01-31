#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector <ll>;

int main() {
	ll numcases; cin >> numcases;
	for (ll i = 0; i < numcases; i++) {
		vi pairs;
		ll count = 0;
		ll minimum = 1000000005;
		ll condition = 0;
		ll n; cin >> n;
		vector<ll>cows;
		for (ll j = 0; j < n; j++) {
			ll temp; cin >> temp;
			cows.push_back(temp);
		}
		if (cows.size() <= 2) {
			for (int i = 0; i < cows.size(); i++) {
				minimum = min(minimum, cows[i]);
			}
		}
		while (cows.size() >= 3) {
			ll current = cows[0];
			ll next = cows[1];
			if (current > next) {
				condition = 1;
				cout << -1 << endl;
				break;
			}
			else {
				ll difference = next - current;
				if (cows[2] - difference >= 0) {
					minimum = min(minimum, cows[2] - difference);
					minimum = min(minimum, current);
					pairs.push_back(current);
					cows[2] -= difference;
					cows.erase(cows.begin());
					cows.erase(cows.begin());
					count += (2 * difference);
				}
				else if (cows[2] - difference < 0) {
					condition = 1;
					cout << -1 << endl;
					break;
				}
			}
		}
		if (condition == 1) {
			continue;
		}
		else {
			if (cows.size() == 2) {
				if (cows[0] == cows[1]) {
					pairs.push_back(cows[0]);
					for (ll m = 0; m < pairs.size(); m++) {
						count += (pairs[m] - minimum) * 2;
					}
					cout << count << endl;
				}
				else {
					cout << -1 << endl;
				}
			}
			
			if (cows.size() == 1) {
				if (cows[0] == minimum) {
					for (ll m = 0; m < pairs.size(); m++) {
						count += (pairs[m] - minimum) * 2;
					}
					cout << count << endl;
				}
				else {
					cout << -1 << endl;
				}
				
			}
		}
	}
}