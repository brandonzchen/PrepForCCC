#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const tuple<int, int, int>& a,
	const tuple<int, int, int>& b)
{
	return (get<1>(a) < get<1>(b));
}

int main() {
	

	//first is less than, second is greater than
	int cows; cin >> cows;
	vector<tuple<int, int, int>> xcomp;
	vector<tuple<int, int, int>> ycomp;
	vector<pair<int, int>> cownumbers;
	for (int i = 1; i <= cows; i++) {
		int x, y; cin >> x >> y;
		pair<int, int> temp;
		temp = make_pair(x, y);
		cownumbers.push_back(temp);
		tuple <int, int, int> tempcomp;
		tempcomp = make_tuple(i, 0, 0);
		xcomp.push_back(tempcomp);
		ycomp.push_back(tempcomp);
	}
	for (int i = 0; i < cows; i++) {
		pair<int, int>currentcomp;
		currentcomp = cownumbers[i];
		for (int j = 0; j < cows; j++) {
			if (cownumbers[j] == currentcomp) {
				continue;
			}
			else {
				if (cownumbers[j].first < currentcomp.first) {
					get<1>(xcomp[i]) += 1;
				}
				if (cownumbers[j].first > currentcomp.first) {
					get<2>(xcomp[i]) += 1;
				}
				if (cownumbers[j].second < currentcomp.second) {
					get<1>(ycomp[i]) += 1;
				}
				if (cownumbers[j].second > currentcomp.second) {
					get<2>(ycomp[i])+= 1;
				}

			}
		}
	}
	sort(xcomp.begin(), xcomp.end(), sortbysec);
	sort(ycomp.begin(), ycomp.end(), sortbysec);
	set<vector<int>> allowed;
	for (int i = 0; i < cows; i++) {
		vector<int>tempcomparison;
		tempcomparison.push_back(get<0>(xcomp[i]));
		for (int j = 0; j < cows; j++) {
			if (xcomp[i] == xcomp[j]) {
				vector<int>t;
				t.push_back(get<0>(xcomp[i]));
				allowed.insert(t);
			}
			else {
				tempcomparison.push_back(get<0>(xcomp[j]));
				sort(tempcomparison.begin(), tempcomparison.end());
				allowed.insert(tempcomparison);
			}
			
		}

	}
	for (int i = 0; i < cows; i++) {
		vector<int>tempcomparison;
		tempcomparison.push_back(get<0>(ycomp[i]));
		for (int j = 0; j < cows; j++) {
			if (ycomp[i] == ycomp[j]) {
				vector<int>t;
				t.push_back(get<0>(ycomp[i]));
				allowed.insert(t);
			}
			else {
				tempcomparison.push_back(get<0>(ycomp[j]));
				sort(tempcomparison.begin(), tempcomparison.end());
				allowed.insert(tempcomparison);
			}

		}

	}
	cout << allowed.size() + 1;

	
}
