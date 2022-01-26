#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5;
int N, fields[maxn + 1];

int main() {
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);

	cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; ++i) {
		cin >> a >> b;
		++fields[a];
		++fields[b];
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i)
		ans = max(ans, fields[i]);

	cout << ans + 1;
}