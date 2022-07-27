#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	int count = 0;
	for (int i = 0; i <= n; i++) {
		if ((n - (i * 4)) % 5 == 0 && (n - (i * 4)) >= 0) {
			count++;
		}
	}
	cout << count;
}