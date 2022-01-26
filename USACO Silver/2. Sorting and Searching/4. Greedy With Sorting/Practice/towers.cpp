#include <bits/stdc++.h>
using namespace std;


//int main() {
//	/*ifstream fin("USACOProblems/Silver/Practice Problems/towerstest.txt");*/
//	int cubes; cin >> cubes;
//	vector<priority_queue<int>>total;
//	
//	for (int i = 0; i < cubes; i++) {
//		int condition = 0;
//		int current; cin >> current;
//		if (total.size() == 0) {
//			priority_queue<int>temp;
//			temp.push(-current);
//			total.push_back(temp);
//		}
//		else {
//			for (auto &j : total) {
//				if (-current > j.top()) {
//					j.push(-current);
//					condition = 1;
//					break;
//				}
//				else if (-current < j.top()) {
//					continue;
//				}
//			 }
//			if (condition == 0) {
//				priority_queue<int>temp1;
//				temp1.push(-current);
//				total.push_back(temp1);
//			}
//		}
//	}
//	cout << total.size();
//}


int main() {
	int cubes; cin >> cubes;
	multiset<int> total;
	for (int i = 0; i < cubes; ++i) {
		int temp; cin >> temp;
		auto it = total.upper_bound(temp);
		if (it == total.end()) total.insert(temp);
		else {
			total.erase(it);
			total.insert(temp);
		}
	}
	cout << total.size();
	return 0;
}