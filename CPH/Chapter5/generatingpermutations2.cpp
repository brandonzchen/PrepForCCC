#include <bits/stdc++.h>
using namespace std;

vector<int>ans = {1,2,3,4};

void print(vector<int>&vec) {
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	do {
		print(ans);
	} while (next_permutation(ans.begin(), ans.end()));
}