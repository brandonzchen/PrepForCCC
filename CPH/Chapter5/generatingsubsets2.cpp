#include <bits/stdc++.h>

using namespace std;

int main() {
	int n = 50000;
	vector<vector<int>> subset;
	for (int b = 0; b < pow(2,n); b++) {
		vector<int>temp;
		
		for (int i = 0; i < n; i++) {
			if (b & (1 << i)) {
				temp.push_back(i);
			}
		}
		subset.push_back(temp);

	}
	for (auto i : subset) {
		for (auto k : i) {
			cout << k << " ";
		}
		cout << endl;
	}

}
