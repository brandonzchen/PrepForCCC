#include <bits/stdc++.h>

using namespace std;

ifstream fin("lineup.in");
ofstream fout("lineup.out");

int main() {
	string order[8] = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
	sort(order, order + 8);
	int n;
	fin >> n;
	vector<pair<string, string>> pairs;
	for (int i = 0; i < n; i++) {
		string a, b, c, d, e, f;
		fin >> a >> b >> c >> d >> e >> f;
		pairs.push_back(make_pair(a, f));
	}
	do {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (find(order, order + 8, pairs[i].first) == find(order, order + 8, pairs[i].second) + 1 || find(order, order + 8, pairs[i].first) == find(order, order + 8, pairs[i].second) - 1) count++;
		}
		if (count == n) {
			for (int i = 0; i < 8; i++) fout << order[i] << endl;
			break;
		}
	} while (next_permutation(order, order + 8));
}