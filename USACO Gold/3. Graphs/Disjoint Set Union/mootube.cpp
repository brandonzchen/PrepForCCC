#include <bits/stdc++.h>
using namespace std;
int parent[200005];
int find(int x) {
	if (x == parent[x]) {
		return parent[x];
	}
	else {
		return parent[x] = find(parent[x]);
	}
}
int main() {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	int n, k;
	cin >> n >> k;

	int cnt[n + 1];
	vector<int> aj[n + 1];

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}
	vector <tuple<int, int, int>> t;
	vector <int> tsrt;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		aj[a].push_back(b);
		aj[b].push_back(a);
		t.push_back({ c,a,b });
		tsrt.push_back(c);
	}
	sort(tsrt.begin(), tsrt.end());
	sort(t.begin(), t.end());
	vector <tuple<int, int, int>> v;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b,i });

	}
	sort(v.rbegin(), v.rend());
	bool vis[k + 1] = { false };
	int answer[k];
	int m = 1;
	int lst = n - 1;
	for (int i = 0; i < v.size(); i++) {
		int ans = 0;
		auto it = lower_bound(tsrt.begin(), tsrt.end(), get<0>(v[i]));
		for (int j = (it - tsrt.begin()); j < lst; j++) {


			int fir = find(get<1>(t[j]));
			int sec = find(get<2>(t[j]));

			if (fir != sec) {

				parent[fir] = sec;
				cnt[sec] += cnt[fir];
				int thr = find(get<1>(v[i]));

				if (sec == thr) {
					ans = cnt[sec] - 1;
				}


			}
		}
		lst = (it - tsrt.begin());
		int thro = find(get<1>(v[i]));
		answer[get<2>(v[i])] = cnt[thro] - 1;


	}
	for (int i = 0; i < k; i++) {
		cout << answer[i] << endl;
	}

}