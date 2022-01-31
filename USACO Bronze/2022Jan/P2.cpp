 #include <bits/stdc++.h>
 using namespace std;
 using vi = vector<int>;
 vector<vi>possible;
 int main() {
 	for (int i = 1; i <= 10; i++) {
 		for (int j = 1; j <= 10; j++) {
 			for (int h = 1; h <= 10; h++) {
 				for (int t = 1; t <= 10; t++) {
 					vi temp = { i,j,h,t };
 					possible.push_back(temp);
 				}
 			}
 		}
 	}
 	int numcases; cin >> numcases;
 	for (int i = 0; i < numcases; i++) {
 		vi a;
 		vi b;
 		for (int j = 0; j < 4; j++) {
 			int temp1; cin >> temp1;
 			a.push_back(temp1);
 		}
 		for (int j = 0; j < 4; j++) {
 			int temp1; cin >> temp1;
 			b.push_back(temp1);
 		}
 		int awin = 0, bwin = 0;
 		for (int j = 0; j < 4; j++) {
 			for (int h = 0; h < 4; h++) {
 				if (a[j] > b[h]) {
 					awin++;
 				}
 				else if (b[h] > a[j]) {
 					bwin++;
 				}
 			}
 		}
 		vi winning;
 		vi losing;
 		if (awin > bwin) {
 			winning = a;
 			losing = b;
 		}
 		else {
 			winning = b;
 			losing = a;
 		}
 		int condition;
 		for (int y = 0; y < possible.size(); y++) {
 			vi current = possible[y];
 			condition = 0;
 			int winlose = 0, winwin = 0, losewin = 0, loselose = 0;
 			for (int d = 0; d < 4; d++) {
 				for (int q = 0; q < 4; q++) {
 					if (winning[q] > current[d]) {
 						winwin++;
 					}
 					if (winning[q] < current[d]) {
 						winlose++;
 					}
 					if (losing[q] > current[d]) {
 						losewin++;
 					}
 					if (losing[q] < current[d]) {
 						loselose++;
 					}
 				}
 			}
 			if (winlose > winwin && losewin > loselose) {
 				cout << "yes" << endl;;
 				condition = 1;
 				break;
 			}
 		}
 		if (condition == 0) {
 			cout << "no" << endl;
 		}
 	}
 } 