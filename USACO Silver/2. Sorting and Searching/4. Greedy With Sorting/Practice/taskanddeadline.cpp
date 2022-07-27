#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	/*ifstream fin("USACOProblems/Silver/Practice Problems/taskanddeadlinetest.txt");*/
	ll count = 0, points = 0;
	ll lines; cin >> lines;
	vector<pair<ll, ll>>comb;
	for (int i = 0; i < lines; i++) {
		ll temp1, temp2; cin >> temp1 >> temp2;
		pair<ll, ll>temp;
		temp = make_pair(temp1, temp2);
		comb.push_back(temp);
	}
	sort(comb.begin(), comb.end());

	for (ll j = 0; j < lines; j++) {
		count += comb[j].first;
		points += comb[j].second - count;
	}
	cout << points;

}