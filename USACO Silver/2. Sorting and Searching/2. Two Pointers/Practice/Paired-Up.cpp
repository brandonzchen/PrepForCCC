#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;

int main() {
	//ifstream fin("pairup.in");
	//ofstream fout("pairup.out");
	int cownum;
	cin >> cownum;
	vector<ll>cowsmilk;
	ll totalcows = 0;
	for (ll i = 0; i < cownum; i++) {
		ll temp1, temp2; cin >> temp1 >> temp2;
		totalcows += temp1;
		for (ll j = 0; j < temp1; j++) {
			cowsmilk.push_back(temp2);
		}
	}
	totalcows--;
	sort(cowsmilk.begin(), cowsmilk.end());
	ll max = 0;
	for (ll i = 0; i < (totalcows / 2); i++) {
		if (cowsmilk[i] + cowsmilk[totalcows - i - 1] > max) {
			max = cowsmilk[i] + cowsmilk[totalcows - i];
		}
	}
	cout << max;
}