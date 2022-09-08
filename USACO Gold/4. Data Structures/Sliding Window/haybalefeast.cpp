#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	vector<long long> f(n), s(n);
	for (int i = 0; i < n; i++) {
		cin >> f[i] >> s[i];
	}
	long long l = 0, r = 0, cf = f[0], ans = INT_MAX;
	multiset<long long> cs;
	cs.insert(s[0]);
	while (l < n && r < n) {
		if (cf >= m) {
			ans = min(ans, *(--cs.end()));
			cf -= f[l];
			cs.erase(cs.find(s[l]));
			l += 1;
		}
		else {
			r += 1;
			cf += f[r];
			cs.insert(s[r]);
		}
	}
	cout << ans;
}
