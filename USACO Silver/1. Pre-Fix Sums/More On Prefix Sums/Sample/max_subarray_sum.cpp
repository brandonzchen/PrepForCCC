#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll numbers; cin >> numbers;
	vector<ll>list(numbers + 1);
	for (ll i = 1; i <= numbers; i++) {
		ll temp; cin >> temp;
		list[i] = list[i - 1] + temp;
	}
	
	ll maxsub = list[1];
	ll minpre = list[0];
	for (ll k = 1; k < list.size(); k++) {
		maxsub = max(maxsub, list[k] - minpre);
		minpre = min(minpre, list[k]);
	}
	cout << maxsub;
}

