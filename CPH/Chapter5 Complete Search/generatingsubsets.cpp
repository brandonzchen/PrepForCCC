#include <bits/stdc++.h>

using namespace std;
vector<int>subset;
void search(int k) {
	if (k == 3) {
		for (auto i : subset) {
			cout << i << " ";
		}
		cout << endl;
	}
	else {
		search(k + 1);
		subset.push_back(k);
		search(k + 1);
		subset.pop_back();
	}
}

int main(){
	search(0);	
}
