//#include <bits/stdc++.h>
//using namespace std;
//
//int K, N;
//
//int main() {
//	freopen("race.in", "r", stdin);
//	freopen("race.out", "w", stdout);
//
//	cin >> K >> N;
//	for (int i = 0; i < N; ++i) {
//		int X, l = 0, r = 0, t = 0;
//		cin >> X;
//
//		for (int curr = 1;; ++curr) {
//			l += curr; 
//			++t;
//			if (l + r >= K) {
//				cout << t << endl;;
//				break;
//			}
//			if (curr >= X) {
//				r += curr; 
//				++t; 
//				if (l + r >= K) {
//					cout << t << endl;
//					break;
//				}
//			}
//		}
//	}
//}

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;


int main() {
	int numcases; cin >> numcases;
	for (int i = 0; i < numcases; i++) {
		vi pairs;
		int count = 0;
		int minimum = 100005;
		int condition = 0;
		int n; cin >> n;
		vector<int>cows;
		for (int j = 0; j < n; j++) {
			int temp; cin >> temp;
			cows.push_back(temp);
		}
		while (cows.size() >= 3) {
			int current = cows[0];
			int next = cows[1];
			if (current > next) {
				condition = 1;
				cout << -1 << endl;
				break;
			}
			else {
				int difference = next - current;
				if (cows[2] - difference >= 0) {
					minimum = min(minimum, cows[2] - difference);
					minimum = min(minimum, current);
					pairs.push_back(current);
					cows[2] -= difference;
					cows.erase(cows.begin());
					cows.erase(cows.begin());
					count += (2 * difference);
				}
				else if (cows[2] - difference < 0) {
					condition = 1;
					cout << -1 << endl;
					break;
				}
			}
		}
		if (condition == 1) {
			continue;
		}
		else {
			if (cows.size() == 2) {
				if (cows[0] == cows[1]) {
					pairs.push_back(cows[0]);
					for (int m = 0; m < pairs.size(); m++) {
						count += (pairs[m] - minimum) * 2;
					}
					cout << count << endl;
				}
				else {
					cout << -1 << endl;
				}
			}
			if (cows.size() == 1) {
				if (cows[0] == minimum) {
					pairs.push_back(cows[0]);
					for (int m = 0; m < pairs.size(); m++) {
						count += (pairs[m] - minimum) * 2;
					}
					cout << count << endl;
				}
				else {
					cout << -1 << endl;
				}
			}
		}
	}
}
