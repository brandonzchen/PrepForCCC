#include <bits/stdc++.h>
using namespace std;

int main() {

	long long n, m;
	cin >> n >> m;
	long long x, y;
	cin >> x >> y;
	long long t;
	string s;
	cin >> t >> s;
	long long addx = 0;
	long long addy = 0;
	for (int i = 0; i < t; i++) {
		if (s[i % t] == 'U') {
			addy++;
		}
		else if (s[i % t] == 'D') {
			addy--;
		}
		else if (s[i % t] == 'L') {
			addx--;
		}
		else {
			addx++;
		}

	}
	long long lo = 0;
	long long hi = 1000000000000000;
	long long ans = -1;
	while (lo < hi) {
		long long mid = (lo + hi) / 2;
		long long posx = n;
		long long posy = m;
		posy += addy * (mid / t);
		posx += addx * (mid / t);

		for (int i = 0; i < mid % t; i++) {
			if (s[i % t] == 'U') {
				posy++;
			}
			else if (s[i % t] == 'D') {
				posy--;
			}
			else if (s[i % t] == 'L') {
				posx--;
			}
			else {
				posx++;
			}

		}
		long long num = abs(x - posx) + abs(y - posy);

		if (num <= mid) {

			ans = mid;
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans;
}