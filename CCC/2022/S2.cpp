#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int count1 = 0;
	//int x; cin >> x;
	//vector<vector<string>>allowed;
	//for (int i = 0; i < x; i++) {
	//	string first, second; 
	//	cin >> first >> second;
	//	vector<string> temp; 
	//	temp.push_back(first);
	//	temp.push_back(second);
	//	allowed.push_back(temp);
	//}
	//int y; cin >> y;
	//vector<vector<string>>notallowed;
	//for (int i = 0; i < y; i++) {
	//	string first, second;
	//	cin >> first >> second;
	//	vector<string> temp;
	//	temp.push_back(first);
	//	temp.push_back(second);
	//	notallowed.push_back(temp);
	//}
	//int z; cin >> z;
	//vector<vector<string>>groups;
	//for (int i = 0; i < z; i++) {
	//	string first, second, third;
	//	cin >> first >> second >> third;
	//	vector<string> temp;
	//	temp.push_back(first);
	//	temp.push_back(second);
	//	temp.push_back(third);
	//	groups.push_back(temp);
	//}

	//for (auto i : allowed) {
	//	for (auto j : groups) {
	//		if (count(j.begin(), j.end(), i[0]) && count(j.begin(), j.end(), i[1]) == false) {
	//			count1++;
	//			break;
	//		}
	//	}
	//}
	//for (auto i : notallowed) {
	//	for (auto j : groups) {
	//		if (count(j.begin(), j.end(), i[0]) && count(j.begin(), j.end(), i[1])) {
	//			count1++;
	//			break;
	//		}
	//	}
	//}
	//cout << count1;
	map < string, vector<string>>allowed;
	map < string, vector<string>>notallowed;
	vector<vector<string>>groups;
	int count1 = 0;
	int x; cin >> x;
	for (int i = 0; i < x; i++) {
		string first1, second1; cin >> first1 >> second1;
		allowed[first1].push_back( second1);
	}
	int y; cin >> y;
	for (int i = 0; i < y; i++) {
		string first1, second1; cin >> first1 >> second1;
		notallowed[first1].push_back( second1);
	}
	int z; cin >> z;
	for (int i = 0; i < z; i++) {
		string first1, second1, third1; cin >> first1 >> second1 >> third1;
		vector<string>temp;
		temp.push_back(first1);
		temp.push_back(second1);
		temp.push_back(third1);
		groups.push_back(temp);
	}
	for (auto i : groups) {
		for (auto j : i) {
			//if (allowed.find(j) == allowed.end()) {
			//	continue;
			//}
			for (auto k : allowed[j]) {
				if (count(i.begin(), i.end(), k) == false) {
					count1++;
				}
			}
			//if (notallowed.find(j) == notallowed.end()) {
			//	continue;
			//}

			for (auto l : notallowed[j]) {
				if (count(i.begin(), i.end(), l)) {
					count1++;
				}
			}
			
		}
	}
	cout << count1;
	
	

}