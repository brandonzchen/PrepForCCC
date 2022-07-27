#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ifstream fin("USACOProblems/Silver/Practice Problems/testfiles1.txt");
	/*freopen("div7.out", "r", stdin);*/
	//freopen("div7.out", "w", stdout);
	ll cows;
	fin >> cows;


	vector<ll> first(7, -1);
	first[0] = 0;
	ll longest = 0;

	ll remainder = 0;

	for (ll i = 1; i <= cows; i++) {
		ll current;
		fin >> current;

		remainder = (remainder + current) % 7;
		if (first[remainder] == -1) {
			first[remainder] = i;
		}
		else {
			longest = max(longest, i - first[remainder]);
		}
	}
	cout << longest << endl;
} 