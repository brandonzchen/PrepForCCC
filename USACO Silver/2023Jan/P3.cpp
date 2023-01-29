#include <bits/stdc++.h>
using namespace std;

int main() {
	int max; 
	cin >> max;
	vector<int>spaces;
	int cond = 0;
	char dir = 'R';
	for (int i = 0; i < max; i++) {
		int temp; cin >> temp;
		spaces.push_back(temp);
	}
	int breakpoint = -1;
	while (cond == 0) {
		if (dir == 'R') {
			for (int i = breakpoint + 1; i < spaces.size(); i++) {
				if (spaces[i] - 1 == 1) {
					spaces[i]--;
					cout << "R";
					breakpoint = i;
				}
				else if(spaces[i] - 1 > 1) {
					spaces[i]--;
					cout << "R";
				}
			}
			dir = 'L';
		}
		else if (dir == 'L') {
			if (breakpoint == spaces.size() - 1) {
				while (spaces.size() != 0) {
					if (spaces[spaces.size() - 1] == 1) {
						cout << "L";
						spaces.pop_back();
					}
					else {
						break;
					}
				}
				for (int i = spaces.size() - 1; i >= 0; i--) {
					if (spaces[i] - 1 == 0) {
						breakpoint = i;
						break;
					}
					else {
						spaces[i]--;
						cout << "L";
					}
					breakpoint = -1;
				}
			}
			else {
				for (int i = spaces.size() - 1; i > breakpoint; i--) {
					spaces[i]--;
					cout << "L";
				}
			}
			dir = 'R';
		}
		if (spaces.size() == 0) {
			cond = 1;
		}
	}

}