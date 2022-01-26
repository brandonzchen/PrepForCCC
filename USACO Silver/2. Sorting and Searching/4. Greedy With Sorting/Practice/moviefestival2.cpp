#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool sortSecond(pair<ll, ll>temp1, pair<ll, ll>temp2) {
	return(temp1.second < temp2.second);
}
//int main() {
//	/*ifstream fin("USACOProblems/Silver/Practice Problems/moviefestival2test.txt");*/
//	ll count = 0;
//	ll movies, people; cin >> movies >> people;
//	vector<pair<ll, ll>>schedule;
//	for (ll i = 0; i < movies; i++) {
//		ll start, end; cin >> start >> end;
//		pair<ll, ll>temp;
//		temp = make_pair(start, end);
//		schedule.push_back(temp);
//	}
//	sort(schedule.begin(), schedule.end(), sortSecond);
//	int pointer = 0;
//	for (ll j = 0; j < people; j++) {
//		count++;
//		ll runningcount = schedule[0].second;
//		for (ll k = 0; k < schedule.size(); k++) {
//			if (schedule[k].first >= runningcount) {
//				runningcount = schedule[k].second;
//				count++;
//				schedule.erase(schedule.begin() + k);
//				k -= 1;
//			  }
//		}
//		schedule.erase(schedule.begin());
//	}
//	cout << count;
//}

int main() {	
	int movies, people; cin >> movies >> people;
	int count = 0;
	vector<pair<int, int>>schedule;
	for (int i = 0; i < movies; i++) {
		pair<int, int>temp;
		int start, end; cin >> start >> end;
		temp = make_pair(start, end);
		schedule.push_back(temp);
	}
	sort(schedule.begin(), schedule.end(), sortSecond);
	multiset<int> endtimes;
	for (int k = 0; k < people; k++) {
		endtimes.insert(0);
	}
	for (int j = 0; j < movies; j++) {
		auto current = endtimes.upper_bound(schedule[j].first);
		if (current == endtimes.begin()) continue;
		endtimes.erase(--current);
		endtimes.insert(schedule[j].second);
		count++;

	}
	cout << count;

}