#include <bits/stdc++.h>

using namespace std;
//
//ifstream fin("lineup.in");
//ofstream fout("lineup.out");
//
//int main() {
//	string order[8] = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
//	sort(order, order + 8);
//	int n;
//	fin >> n;
//	vector<pair<string, string>> pairs;
//	for (int i = 0; i < n; i++) {
//		string a, b, c, d, e, f;
//		fin >> a >> b >> c >> d >> e >> f;
//		pairs.push_back(make_pair(a, f));
//	}
//	do {
//		int count = 0;
//		for (int i = 0; i < n; i++) {
//			if (find(order, order + 8, pairs[i].first) == find(order, order + 8, pairs[i].second) + 1 || find(order, order + 8, pairs[i].first) == find(order, order + 8, pairs[i].second) - 1) count++;
//		}
//		if (count == n) {
//			for (int i = 0; i < 8; i++) fout << order[i] << endl;
//			break;
//		}
//	} while (next_permutation(order, order + 8));
//}

int N;
string cows[8] = { "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue" }, constraints[7][2];

int index(string cow) {
    for (int i = 0; i < 8; ++i)
        if (cow == cows[i])
            return i;
    return -1;
}

bool valid() {
    for (int i = 0; i < N; ++i)
        if (abs(index(constraints[i][0]) - index(constraints[i][1])) != 1)
            return 0;
    return 1;
}

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string a, b, t;
        cin >> constraints[i][0] >> t >> t >> t >> t >> constraints[i][1];
    }
    do {
        if (valid()) {
            for (int i = 0; i < 8; ++i)
                cout << cows[i] << endl;
            return 0;
        }
    } 
    while (next_permutation(cows, cows + 8));
}