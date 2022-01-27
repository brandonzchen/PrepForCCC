#include <bits/stdc++.h>
using namespace std;
int main() {

	freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);
	int n, t;
	string want;
	cin >> n >> t >> want;
	int lo = n, hi = 0;
	vector<int> A(251, -1), B(251, -1), seen(n);
	for (int i = 0; i < t; ++i) {
		int time, a, b;
		cin >> time >> a >> b;
		A[time] = a - 1;
		B[time] = b - 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k <= n + 1; ++k) {
			vector<int> infect(n), remain(n);
			infect[i] = 1;
			remain[i] = k;
			for (int time = 1; time <= 250; ++time) {
				if (A[time] == -1) continue;
				int a = A[time], b = B[time];
				if (!infect[a] && remain[b] > 0) {
					infect[a] = 1;
					remain[a] = k + 1;
				}
				if (!infect[b] && remain[a] > 0) {
					infect[b] = 1;
					remain[b] = k + 1;
				}
				if (infect[a]) remain[a]--;
				if (infect[b]) remain[b]--;
			}
			bool good = true;
			for (int i = 0; i < n; ++i) {
				if ((want[i] == '1') != infect[i]) {
					good = false;
					break;
				}
			}
			if (good) {
				lo = min(lo, k);
				hi = max(hi, k);
				seen[i] = 1;
			}
		}
	}
	cout << accumulate(seen.begin(), seen.end(), 0) << ' ' << lo << ' ';
	if (hi == n + 1) cout << "Infinity";
	else cout << hi;
}