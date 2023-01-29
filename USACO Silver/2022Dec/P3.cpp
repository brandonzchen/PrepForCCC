#include<bits/stdc++.h>
using namespace std;

int main() {
	/*ifstream fin("USACO Silver/2022Dec/test.in");*/
	int cows; cin >> cows;
	vector<vector<int>> minmax(cows + 1, vector<int>{});
	for (int i = cows; i > 0; i--) {
		for (int j = i; j > 0; j--) {
			int temp; cin >> temp;
			minmax[cows - i + 1].push_back(temp);
		}
	}
	vector<int>solution( cows + 1);
	solution[cows] = 0;
	solution[cows - 1] = minmax[cows - 1][1];
	for (int i = cows - 2; i > 0; i--) {
		if (minmax[i][1] == 0) {
			solution[i] = solution[i + 1];
		}
		else {
			solution[i] = solution[i + 1] + minmax[i][1];
			int tempmin = solution[i];
			int tempmax = solution[i];
			int pointer = i;
			for (int j = 1; j < minmax[i].size(); j++) {
				tempmin = min(tempmin, solution[pointer + 1]);
				tempmax = max(tempmax, solution[pointer + 1]);
				if (tempmax - tempmin != minmax[i][j]) {
					solution[i] = solution[i + 1] - minmax[i][1];
					break;
				}
				if (tempmax - tempmin == minmax[i][j]) {
					pointer++;
				}
			}
		}
		

	}
	for (int i = 1; i < solution.size(); i++) {
		if (i != cows) {
			cout << solution[i] << " ";
		}
		else {
			cout << solution[i];
		}
	}
}
