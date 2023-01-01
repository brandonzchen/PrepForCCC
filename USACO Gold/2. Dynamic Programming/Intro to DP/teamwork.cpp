#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ifstream cin ("teamwork.in");
	ofstream cout ("teamwork.out");

	ll n, k; cin >> n >> k;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<ll> dp(n + 1, 0);


	for (int i = 1; i <= n; i++) {
		ll mx = v[i - 1];
		for (int j = 1; j <= k && j <= i; j++) {
			mx = max(mx, v[i - j]);
			dp[i] = max(dp[i], dp[i - j] + mx * j);
		}
	}
	cout << dp[n] << endl;
}