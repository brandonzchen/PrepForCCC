#include <bits/stdc++.h>
using namespace std;

int main() {
	int numbers; cin >> numbers;
	vector<int>order;
	int count = 0;
	for (int i = 0; i < numbers; i++) {
		int temp; cin >> temp;
		order.push_back(temp);
	}
	for (int i = 0; i < order.size(); i++) {
		int maximum = 0;
		for (int j = i; j < order.size(); j++) {
			if (j > i  && maximum <= order[i]) {
				maximum = max(maximum, order[j]);
				if (order[j] >= maximum) {
					count = count + j - i + 1;
				}
			}
		}
	}
	cout << count;
}