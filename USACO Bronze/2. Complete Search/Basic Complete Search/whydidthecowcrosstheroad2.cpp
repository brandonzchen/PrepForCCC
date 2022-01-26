#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	string paths;
	cin >> paths;
	int count = 0;
	int d1, d2, d3, d4;

	for (char i = 'A'; i <= 'Z'; i++) {
		for (char j = 'A'; j <= 'Z'; j++) {
			d1 = paths.find(i);
			d2 = paths.find(j);
			d3 = paths.find_last_of(i);
			d4 = paths.find_last_of(j);
			count += d1 < d2&& d2 < d3&& d3 < d4;
		}
	}
	cout << count;
	return 0;
}