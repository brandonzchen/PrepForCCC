#include <bits/stdc++.h>
using namespace std;

int main() {
	int people; cin >> people;
	vector <pair<int, int>> ad;
	for (int i = 0; i < people; i++) {
		int a, d; cin >> a >> d;
		pair<int, int> temp;
		temp.first = a;
		temp.second = d;
		ad.push_back(temp);
	}
	priority_queue<int>dvsa;
	sort(ad.begin(), ad.end());
	dvsa.push(-ad[0].second);
	int maximum = dvsa.size();

	for (int i = 1; i < ad.size(); i++) {
		if (dvsa.top() <= (-ad[i].first))
		{
			dvsa.push(-ad[i].second);
		}
		if (dvsa.top() > (-ad[i].first))
		{
			dvsa.pop();
			dvsa.push(-ad[i].second);

		}
		int current = dvsa.size();
		maximum = max(maximum, current);
	}

	cout << maximum;
}