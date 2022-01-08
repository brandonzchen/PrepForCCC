#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> subset;

void gensub (int n){ 

	for (int b = 0; b < pow(2, n); b++) {
		vector<int>temp;
		for (int i = 0; i < n; i++) {
			if (b & (1 << i)) {
				temp.push_back(i);
			}
		}
		subset.push_back(temp);
	}
}
int main() {
	int cows; cin >> cows;
	vector < pair< int, int > > coords;
	for (int i = 0; i < cows; i++) {
		int temp1, temp2; cin >> temp1 >> temp2;
		pair<int, int> tempcoords;
		tempcoords.first = temp1;
		tempcoords.second = temp2;
		coords.push_back(tempcoords);
	}
	sort(coords.begin(), coords.end());
	for (int i = 1; i < cows; i++) {
		int firstx = coords[0].first - coords[i].first;
		int maxy = coords[0].second;
		int maxy = max(maxy, coords[i].second);
	}





}