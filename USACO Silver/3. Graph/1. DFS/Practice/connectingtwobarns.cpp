#include <bits/stdc++.h>
using namespace std;


int main() {
	int subcases; cin >> subcases;
	for (int i = 0; i < subcases; i++) {
		int fields, paths; cin >> fields >> paths;
		set<int> possiblestart;
		map<int, vector<int>> graph;
		for (int j = 0; j < paths; j++) {
			int first, second; cin >> first >> second;
			graph[first].push_back(second);
			graph[second].push_back(first);
		}
		stack <int> dfs;
		dfs.push(1);
		possiblestart.insert(1);
		while (dfs.size() != 0) {
			vector<int> current; 
			current = graph[dfs.top()];
			dfs.pop();
			for (auto l : current) {
				int setsize; 
				setsize = possiblestart.size();
				possiblestart.insert(l);
				if (setsize != possiblestart.size()) {
					dfs.push(l);
				}
			}
		}
		set<int> possibleend;
		possibleend.insert(fields);
		dfs.push(fields);
		while (dfs.size() != 0) {
			vector<int> current;
			current = graph[dfs.top()];
			dfs.pop();
			for (auto l : current) {
				int setsize;
				setsize = possibleend.size();
				possibleend.insert(l);
				if (setsize != possibleend.size()) {

					dfs.push(l);
				}
			}

		}
		int endbegin = *(--possibleend.rend());
		int startend = *possiblestart.rbegin();
		int mincost = pow(endbegin - startend, 2);
		set<int> visitedsecond;
		visitedsecond.insert(startend);
		for (int j = startend + 1; j <= fields; j++) {
			int tempsize = visitedsecond.size();
			visitedsecond.insert(j);
			if (visitedsecond.size() != tempsize) {
				int tempcost = pow(j - startend, 2);
				set<int> reachable;
				reachable.insert(j);
				dfs.push(j);
				while (dfs.size() != 0) {
					vector<int> current;
					current = graph[dfs.top()];
					dfs.pop();
					for (auto l : current) {
						int setsize;
						setsize = reachable.size();
						reachable.insert(l);
						if (setsize != reachable.size()) {

							dfs.push(l);
							visitedsecond.insert(l);
						}
					}

				}
				int endreachable = *reachable.rbegin();
				tempcost += pow(endbegin - endreachable, 2);
				mincost = min(mincost, tempcost);
			}
		}
		cout << mincost << endl;
	}
}
