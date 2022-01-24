#include <bits/stdc++.h>
using namespace std;

vector<int> permutation;
int n = 4;
//array<int, 4> chosen = { 1,2,3,4 };
bool chosen[4];
string items[4]{"apple", "orange", "pear", "melon"};

void search() {
	if (permutation.size() == n) {
		for (auto i : permutation) {
			cout << items[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (chosen[i]) continue;
			chosen[i] = true;
			permutation.push_back(i);
			search();
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}

int main() {
	search();
}