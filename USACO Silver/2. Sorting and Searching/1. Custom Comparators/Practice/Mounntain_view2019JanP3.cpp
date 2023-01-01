#include <bits/stdc++.h>
//
//using namespace std;
//using ll = long long;
//
//bool decendingpair(const pair<ll, ll>& a, const pair<ll, ll>& b) {
//	return a.second > b.second;
//}
//int main() {
//	ifstream cin("mountains.in");
//	ofstream cout("mountains.out");
//	int mountains;
//	cin >> mountains;
//	int actualmountains = 0;
//	vector<pair<ll, ll>> coords;
//	for (int i = 0; i < mountains; i++) {
//		int x, y;
//		cin >> x >> y;
//		pair<ll, ll>temp{ x, y };
//		coords.push_back(temp);
//	}
//	sort(coords.begin(), coords.end(), decendingpair);
//	queue <pair<ll, ll>> mountainorder;
//	mountainorder.push(coords[0]);
//	set<pair<ll, ll>>testing;
//
//	do {
//		for (int i = 0; i < coords.size(); i++) {
//			if (mountainorder.front() == coords[i]) {
//				coords.erase(coords.begin());
//				i--;
//				continue;
//			}
//			else {
//				ll xdiff = abs(mountainorder.front().first - coords[i].first);
//				ll ydiff = abs(mountainorder.front().second - coords[i].second);
//				if (xdiff < ydiff) {
//					ll beforesize;
//					beforesize = testing.size();
//					testing.insert(coords[i]);
//					if (beforesize == testing.size()) {
//						continue;
//					}
//					else {
//						mountainorder.push(coords[i]);
//					}
//				}
//				else {
//					coords.erase(coords.begin() + i);
//					i--;
//				}
//			}
//		}
//		mountainorder.pop();
//		actualmountains++;
//	} while (mountainorder.size() != 0);
//	cout << actualmountains;
//}


using namespace std;
#define MAXN 100000

int N;
int x[MAXN], y[MAXN];
int pos[MAXN], neg[MAXN];
int cid[MAXN];

bool cmp(int a, int b)
{
	if (neg[a] == neg[b])
		return pos[a] > pos[b];
	return neg[a] < neg[b];
}

int main()
{
	ifstream cin("mountains.in");
	ofstream cout("mountains.out");
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x[i] >> y[i];
		pos[i] = x[i] + y[i], neg[i] = x[i] - y[i];
		cid[i] = i;
	}
	sort(cid, cid + N, cmp);
	int mxpos = -1;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (pos[cid[i]] > mxpos)
		{
			ans++;
			mxpos = pos[cid[i]];
		}
	}
	cout << ans << '\n';
}

