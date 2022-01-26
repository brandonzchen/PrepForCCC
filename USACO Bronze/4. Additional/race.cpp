#include <bits/stdc++.h>
using namespace std;

int K, N;

int main() {
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);

	cin >> K >> N;
	for (int i = 0; i < N; ++i) {
		int X, l = 0, r = 0, t = 0;
		cin >> X;

		for (int curr = 1;; ++curr) {
			l += curr; 
			++t;
			if (l + r >= K) {
				cout << t << endl;;
				break;
			}
			if (curr >= X) {
				r += curr; 
				++t; 
				if (l + r >= K) {
					cout << t << endl;
					break;
				}
			}
		}
	}
}