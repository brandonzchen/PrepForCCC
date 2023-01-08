#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int , int>;


int main() {

	int people; cin >> people;
	vector<ti>se;
	for (int i = 0; i < people; i++) {
		int first, last; cin >> first >> last;
		ti temp{first, last, i};
		se.push_back(temp);
	}
	sort(se.begin(), se.end());
	vector <int> rooms {0};
	int roomsize = 0;
	vector<pi> print;
	for (int j = 0; j < people; j++) {
		int condition = 0;
		for (int k = 0; k < rooms.size(); k++) {
			if (get<0>(se[j]) > rooms[k]) {
				rooms[k] = get<1>(se[j]);
				condition = 1;
				pi temp1{get<2>(se[j]), k+1 };
				print.push_back(temp1);
				break;
			}
		}
		if (condition == 0) {
			rooms.push_back(get<1>(se[j]));
			pi temp1{ get<2>(se[j]),rooms.size()  };
			print.push_back(temp1);
		}
	}
	cout << rooms.size() << endl;
	sort(print.begin(), print.end());
	for (auto i : print) {
		cout << i.second << " ";
	}
}

