
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream cin("pairup.in");
	ofstream cout("pairup.out");
	int n;
	cin >> n;
	vector <pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end());
	int fir = 0;
	int sec = n - 1;
	int ans = 0;
	while (fir <= sec) {
		if (fir == sec) {
			ans = max(ans, v[fir].first * 2);
			break;
		}
		else {
			if (v[fir].second > v[sec].second) {
				v[fir].second -= v[sec].second;

				ans = max(ans, v[fir].first + v[sec].first);
				sec--;
			}
			else if (v[fir].second < v[sec].second) {
				v[sec].second -= v[fir].second;
				ans = max(ans, v[fir].first + v[sec].first);
				fir++;
			}
			else {
				ans = max(ans, v[fir].first + v[sec].first);
				fir++;
				sec--;
			}
		}
	}
	cout << ans;
	return 0;
}