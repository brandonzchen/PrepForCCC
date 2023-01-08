#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream cin ("cardgame.in");
	ofstream cout("cardgame.out");
	int cards; cin >> cards;
	vector<int> elsie(cards);
	deque<int> bessie;
	for (int i = 1; i <= 2 * cards; ++i) {
		bessie.push_back(i);
	}
	for (int i = 0; i < cards; ++i) {
		cin >> elsie[i];
		bessie.erase(lower_bound(begin(bessie), end(bessie), elsie[i]));
	}
	sort(begin(elsie), begin(elsie) + cards / 2, greater<int>());
	sort(begin(elsie) + cards / 2, end(elsie));
	int points = 0;
	for (int i = 0; i < cards / 2; ++i) {
		if (elsie[i] < bessie.back()) {
			bessie.pop_back();
			++points;
		}
	}
	for (int i = cards / 2; i < cards; ++i) {
		if (elsie[i] > bessie.front()) {
			bessie.pop_front();
			points++;
		}
	}
	cout << points;

}