#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin("mountains.in");
	ofstream fout("mountains.out");
	int N;
	fin >> N;
	vector<pair<long, long>> pos(N, { 0,0 });
	for (int i = 0; i < N; ++i) {
		long x, y;
		fin >> x >> y;
		pos[i] = { x - y,x + y };
	}
	sort(pos.begin(), pos.end());
	int blocked = 0;
	long a0 = pos[0].first;
	long b0 = pos[0].second;
	for (int i = 1; i < N; ++i) {
		long a1 = pos[i].first;
		long b1 = pos[i].second;
		if (a1 == a0 && b0 <= b1) {
			++blocked;
			a0 = a1;
			b0 = b1;
			continue;
		}
		if (a1 >= b0) {
			a0 = a1;
			b0 = b1;
			continue;
		}
		if (b1 <= b0) {
			++blocked;
			continue;
		}
		a0 = a1;
		b0 = b1;
	}
	fout << (N - blocked) << endl;
	return 0;
}