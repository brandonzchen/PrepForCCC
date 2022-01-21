#include <bits/stdc++.h>
using namespace std;

bool sortSecond(pair<int, int>temp1, pair<int, int>temp2) {
	return(temp1.second < temp2.second);
}

int main() {
	int movies, people; cin >> movies >> people;
	vector<pair<int, int>>schedule;
	for (int i = 0; i < movies; i++) {
		int start, end; cin >> start >> end;
		pair<int, int>temp;
		temp = make_pair(start, end);
		schedule.push_back(temp);
	}
	sort(schedule.begin(), schedule.end(), sortSecond);

}