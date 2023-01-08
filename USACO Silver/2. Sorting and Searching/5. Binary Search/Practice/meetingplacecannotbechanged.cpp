#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	long double dist[n];
	long double speed[n];
	for (int i = 0; i < n; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> speed[i];
	}
	long double lo = 0;
	long double hi = 1000000000;
	long double ans;

	while (lo <= hi) {
		long double mid = (lo + hi) / 2;




		long double high = dist[0] + (mid * speed[0]);
		long double low = dist[0] - (mid * speed[0]);

		int roll = 0;
		for (int i = 1; i < n; i++) {
			long double hrange = dist[i] + (mid * speed[i]);
			long double lrange = dist[i] - (mid * speed[i]);
			if (hrange < low || lrange > high) {
				roll = 2;
				break;
			}
			else {
				high = min(high, hrange);
				low = max(low, lrange);
			}

		}

		if (roll == 2) {
			lo = mid + 0.0000001;
		}
		else {

			hi = mid - 0.0000001;
			ans = mid;
		}
	}
	cout.precision(12);

	cout << fixed << ans;
}
