#include <bits/stdc++.h>

using namespace std;
int n, k;
int main() {
	/*ifstream fin("USACOProblems/Silver/Practice Problems/diamond.in");*/
	//ifstream cin("diamond.in");
	//ofstream cout("diamond.out");


	cin >> n >> k;
	vector < int>diamonds;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		diamonds.push_back(temp);
	}
	sort(diamonds.begin(), diamonds.end());


	vector<int>nextdiamond(n);
	int pointer1 = 0, pointer2 = 0;
	for (pointer1; pointer1 < n; pointer1++) {
		while (n > pointer2 && diamonds[pointer2] - diamonds[pointer1] <= k) {
			pointer2++;
		}
		nextdiamond[pointer1] = pointer2 - pointer1;
	}

	vector<int>maxafter(n + 1);
	maxafter[n] = 0;
	for (int i = n - 1; i > 0; i--) {
		maxafter[i] = max(maxafter[i + 1], nextdiamond[i]);
	}

	int ans = 0;
	for (int l = 0; l < n; l++) {
		ans = max(ans, nextdiamond[l] + maxafter[l + nextdiamond[l]]);
	}
	cout << ans << endl;

	return 0;
}