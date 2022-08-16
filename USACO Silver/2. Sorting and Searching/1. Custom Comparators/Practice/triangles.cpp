#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;


int main() {
	ifstream cin ("triangles.in");
	ofstream cout ("triangles.out");
	int n; cin >> n;
	vector<pi> fence(n);
	map<pi, int> pasture;
	for (int i = 0; i < n; i++) {
		cin >> fence[i].first >> fence[i].second;
		pasture[fence[i]] = i;
	}
	
	sort(fence.begin(), fence.end());
	

	vector<ll> sum_vertical(n);
	for (int i = 0; i < n; i++) {
		int j = i + 1, total_same_x = 1;
		while (fence[j].first == fence[i].first) {
			sum_vertical[pasture[fence[i]]] += (fence[j].second - fence[i].second);
			j++;
			total_same_x++;
		}
		j = i + 1;
		ll prefix = sum_vertical[pasture[fence[i]]];
		while (fence[j].first == fence[i].first) {
			sum_vertical[pasture[fence[j]]] = prefix + (fence[j].second - fence[j - 1].second) * (2 * j - 2 * i - total_same_x); 
			j++;
		}
		i = j - 1;
	}


	sort(fence.begin(), fence.end(), [](pi a, pi b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		else {
			return a.second < b.second;
		}
		});
	
	vector<ll> sum_horizontal(n);
	for (int i = 0; i < n; i++) {
		int j = i + 1, total_same_y = 1;
		while (fence[j].second == fence[i].second) {
			sum_horizontal[pasture[fence[i]]] += (fence[j].first - fence[i].first);
			j++;
			total_same_y++;
		}
		j = i + 1;
		ll prefix = sum_horizontal[pasture[fence[i]]];
		while (fence[j].second == fence[i].second) {
			sum_horizontal[pasture[fence[j]]] = prefix + (fence[j].first - fence[j - 1].first) * (2 * j - 2 * i - total_same_y);
			prefix = sum_horizontal[pasture[fence[j]]];
			j++;
		}
		i = j - 1;
	}
	ll sum_of_triangle_areas = 0;
	for (int i = 0; i < n; i++) {
		sum_of_triangle_areas += (sum_horizontal[pasture[fence[i]]] * sum_vertical[pasture[fence[i]]]);
	}
	cout << (sum_of_triangle_areas % 1000000007) << endl;
}