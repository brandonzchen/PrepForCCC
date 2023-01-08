#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream cin("convention2.in");
	ofstream cout("convention2.out");
	int cows; cin >> cows;
	set<int> cowqueue;
	vector<tuple<int, int, int>>arrivalsort;
	vector<tuple<int, int, int>>priosort;
	for (int i = 1; i <= cows; i++) {
		int a, t; cin >> a >> t;
		tuple<int, int, int> temp;
		get<0>(temp) = i;
		get<1>(temp) = a;
		get<2>(temp) = t;
		priosort.push_back(temp);
		tuple<int, int, int> temp2;
		get<0>(temp2) = a;
		get<1>(temp2) = i;
		get<2>(temp2) = t;
		arrivalsort.push_back(temp2);

	}
	sort(arrivalsort.begin(), arrivalsort.end());
	cowqueue.insert(get<1>(arrivalsort[0]));
	int cowsprocessed = 0;
	int cowpointer = 0;
	int totaltime = get<0>(arrivalsort[0]);
	int start = 0;
	int maxwait = 0;
	while (cowsprocessed != cows) {
		if (cowqueue.size() != 0) {
			tuple<int, int, int> currentcow = priosort[*cowqueue.begin() - 1];

			start = totaltime;
			totaltime = start + get<2>(currentcow);
			maxwait = max(start - get<1>(currentcow), maxwait);
			cowqueue.erase(cowqueue.begin());
			bool cond = true;
			while (cond) {
				cowpointer++;
				if (cowpointer < cows) {
					if (get<0>(arrivalsort[cowpointer]) >= start && get<0>(arrivalsort[cowpointer]) <= totaltime) {
						cowqueue.insert(get<1>(arrivalsort[cowpointer]));
					}
					else {
						cond = false;
						cowpointer--;

					}
				}
				else {
					cond = false;
				}
				
			}
			cowsprocessed++;

		}
		else if(cowpointer < cows) {
			cowpointer++;
			cowqueue.insert(get<1>(arrivalsort[cowpointer]));
			totaltime = get<0>(arrivalsort[cowpointer]);

		}
	}
	cout << maxwait;



}