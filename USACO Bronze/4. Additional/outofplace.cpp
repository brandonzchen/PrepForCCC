#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> original(n);
	vector<int> sorted(n);
	for (int i = 0; i < n; i++){
		cin >> original[i];
		sorted[i] = original[i];
	}
	sort(sorted.begin(), sorted.end());
	int swaps = 0;
	for (int i = 0; i < n; i++){
		if (original[i] != sorted[i]){
			swaps++;
		}
	}
	cout << swaps - 1 << endl;
	return 0;
}