#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
#define all(x) x.begin(), x.end()


int main()
{
	ifstream fin("rental.in");
	ofstream fout("rental.out");
	ll n, m, r;
	fin >> n >> m >> r;

	vector<ll> milks(n);
	for (int i = 0; i < n; ++i)
		fin >> milks[i];

	sort(all(milks), greater<ll>());
	vector<pl> sells(m);
	for (int i = 0; i < m; ++i)
		fin >> sells[i].second >> sells[i].first;

	sort(all(sells), greater<pl>());

	vector<ll> rent(r);
	for (int i = 0; i < r; ++i)
		fin >> rent[i];

	sort(all(rent), greater<ll>());

	vector<ll> decision(n);
	ll ans = 0;
	for (int i = n - 1, pos = 0; i >= 0 && pos < r; --i, pos++)
	{
		decision[i] = rent[pos];
		ans += decision[i];
	}

	int pos = 0;
	for (int i = 0; i < n && pos < m; ++i)
	{
		ll to_add = 0;
		ll to_sell = 0;
		ll to_sub = 0;
		ll count = milks[i];
		while (count && pos < m)
		{
			if (count < sells[pos].second)
			{
				to_sell += count * sells[pos].first;
				to_sub = count;
				break;
			}
			else if (count > sells[pos].second)
			{
				to_sell += sells[pos].second * sells[pos].first;
				count -= sells[pos].second;
				pos++;
			}
			else
			{
				to_sell += sells[pos].second * sells[pos].first;
				pos++;
				break;
			}

		}

		to_add = to_sell - decision[i];
		if (to_add > 0)
		{
			//fout << to_sell << endl;
			ans += to_add;
			sells[pos].second -= to_sub;
		}
		/*else
		{
			fout << decision[i] << endl;
		}*/
	}

	fout << ans << endl;
	return 0;
}