#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_SIDE = 1000;
int tree_pref[MAX_SIDE + 1][MAX_SIDE + 1];
int forest[MAX_SIDE + 1][MAX_SIDE + 1];

int main() {

	int N;
	int Q;
	cin >> N >> Q;
	// read in the initial trees
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char a;
			cin >> a;
			forest[i + 1][j + 1] += a == '*';
		}
	}

	// build the prefix sum array
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			tree_pref[i][j] = forest[i][j]
				+ tree_pref[i - 1][j]
				+ tree_pref[i][j - 1]
				- tree_pref[i - 1][j - 1];
		}
	}

	for (int q = 0; q < Q; q++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << tree_pref[x2][y2]
			- tree_pref[x1 - 1][y2]
			- tree_pref[x2][y1 - 1]
			+ tree_pref[x1 - 1][y1 - 1] << '\n';
	}
}