#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> count(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	count[0] = 1;

	for (int i = 1, x = 0; i < n; ++i) {
		if (v[i] == v[i - 1]) count[x]++;
		else {
			x++;
			count[x]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < count.size(); ++i) {
		if (count[i] == 0) break;
		ans++;
	}
	cout << ans << endl;
}