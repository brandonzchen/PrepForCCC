#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ti = tuple<int, int, int>;
using pi = pair<int, int>;
int count1;
int main() {
	//freopen("mootube.in", "r", stdin);
	//freopen("mootube.out", "w", stdout);
	//ifstream fin("USACO Silver/3. Graph/Tree Algorithms/Practice/mootubetest.txt");
	int vids, qs; cin >> vids >> qs;
	vector<ti>original; 
	vector<ti>flipped;
	vector<int> answer;
	for (int i = 0; i < vids - 1; i++) {
		int first, second, weight; cin >> first >> second >> weight;
		ti temp = { first, second, weight };
		ti temp1 = { second, first, weight };
		original.push_back(temp);
		original.push_back(temp1);
	}
	for (int j = 0; j < qs; j++) {
		set<pair<int, int>>tester;
		int k, starting; cin >> k >> starting;
		count1 = 0;
		stack<pi>dfs;
		for (int p = 0; p < original.size(); p++) {
			if (get<0>(original[p]) == starting && get<2>(original[p]) >= k) {
				pi node = { get<1>(original[p]), get<2>(original[p]) };
				tester.insert(node);
				dfs.push(node);
				count1++;
			}
		}
		while (dfs.size() != 0) {
			pi current = dfs.top();
			dfs.pop();
			for (int l = 0; l < original.size(); l++) {
				if (current.first == get<0>(original[l])){
					int minweight = min(current.second, get<2>(original[l]));
					if (minweight >= k) {
						pi newnode = { get<1>(original[l]), get<2>(original[l]) };
						int tsize = tester.size();
						tester.insert(newnode);
						if (tester.size() != tsize) {
							dfs.push(newnode);
							count1++;
						}
					}
				}
			}

		}
		answer.push_back(count1);
	}
	for (auto i : answer) {
		cout << i/2 << endl;
	}
}