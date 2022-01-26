#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	int n, m; cin >> n >> m;
	int x[n], y[n], ver[n], hor[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		ver[i] = x[i] + 1;
		hor[i] = y[i] + 1;
	}
	int ans = n;
	for (int z = 0; z < n; z++) {
		for (int i = 0; i < n; i++) {
			int points = 0;
			int bottomleft = 0;
			int bottomright = 0;
			int topright = 0;
			int topleft = 0;
			for (int k = 0; k < n; k++) {

				if (x[k] < ver[z] && y[k] < hor[i]) {
					bottomleft++;
				}
				else if (x[k] > ver[z] && y[k] < hor[i]) {
					bottomright++;
				}

				else if (x[k]<ver[z] && y[k]>hor[i]) {
					topleft++;
				}
				else if (x[k] > ver[z] && y[k] > hor[i]) {
					topright++;
				}
			} 
			points = max({ bottomleft,bottomright,topleft,topright });
			ans = min(ans, points);
		}
	
	}
	cout << ans << endl;
}