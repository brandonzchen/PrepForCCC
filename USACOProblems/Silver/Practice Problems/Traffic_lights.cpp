#include <bits/stdc++.h>
using namespace std;

int main() {
	int length, lights; cin >> length >> lights;
	set<int>differences{ length - 1 };
	set<int>trafficlights;
	trafficlights.insert(1);
	trafficlights.insert(length);
	for (int i = 0; i < lights; i++) {
		int current; cin >> current;
		auto biggerthan = trafficlights.lower_bound(current);
		auto lessthan = biggerthan--;
		trafficlights.insert(current);

	}
	

}