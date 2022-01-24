#include <bits/stdc++.h>
using namespace std;

int main() {
	int cows; 
	cin >> cows;
	vector <int> differences;
	for (int i = 0; i < cows; i++) {
		int temp; cin >> temp; 
		differences.push_back(temp);
	}
	for (int i = 0; i < cows; i++) {
		int temp1; cin >> temp1;
		differences[i] -= temp1;
	}
	int count = 0;
	for (int j = 0; j < differences.size(); j++) {
		if (differences[j] > 0){
			while (differences[j] != 0) {
				differences[j]--;
				for (int x = j + 1; x < differences.size(); x++) {
					if (differences[x] > 0) {
						differences[x]--;
					}
					else {
						break;
					}

				}
				count++;
			}
		}
		if (differences[j] < 0) {
			while (differences[j] != 0) {
				differences[j]++;
				for (int x = j + 1; x < differences.size(); x++) {
					if (differences[x] < 0) {
						differences[x]++;
					}
					else {
						break;
					}

				}
				count++;
			}
		}
		
	}
	cout << count;
}