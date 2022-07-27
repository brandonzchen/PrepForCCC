#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll notes, max, pieces; cin >> notes >> max >> pieces;
	if (max == 2) {
		ll maxpieces = notes * 2 - 1;
		if (pieces > maxpieces || pieces < notes) {
			cout << -1;
		}
		else {

			ll num2s = maxpieces - pieces + 1;
			if (num2s == notes) {
				for (ll i = 0; i < notes; i++) {
					cout << 1 << " ";
				}
			}
			else {
				cout << 1 << " ";
				for (ll i = 0; i < num2s; i++) {
					cout << 2 << " ";
				}
				ll notesleft = notes - 1 - num2s;
				bool onelast = false;
				for (int j = 0; j < notesleft; j++) {
					if (onelast == true) {
						cout << 2 << " ";
						onelast = false;
					}
					else if (onelast == false) {
						cout << 1 << " ";
						onelast = true;
					}
				}
			}
		}
	}
	else {
		ll maxpieces = 0;
		ll onecount = 0;

		for (ll i = 1; i <= notes; i++) {
			maxpieces += i;
		}
		if (pieces > maxpieces || pieces < notes) {
			cout << -1;
		}
		else {
			ll currentcount = 0;
			cout << 1 << " ";
			ll difference = maxpieces - pieces;
			for (ll i = notes - 1; i > 0; i--) {
				if (difference - i > 0) {
					onecount++;
					difference -= i;
				}
			}
			for (ll i = 0; i < onecount; i++) {
				cout << 1 << " ";
				currentcount++;
			}
			for (ll i = 2; i <= notes - onecount; i++) {
				currentcount++;
				if (currentcount == notes - difference) {
					cout << 1 << " ";
					i - 1;
				}
				else {
					cout << i << " ";
				}
			}
		}
	}


}