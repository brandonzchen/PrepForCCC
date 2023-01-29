#include <bits/stdc++.h>
using namespace std;

char start[100001];
char finish[100001];

int main() {
	int testcases; cin >> testcases;
	for (int i = 0; i < testcases; i++) {
		int cond = 0;
		set<char>usedletters;
		string start; cin >> start;
		string finish; cin >> finish;
		map<char, pair<char, int>> connections;
		int alrset = 0;
		for (int j = 0; j < start.size(); j++) {
			if (connections.count(start[j]) == 0) {
				connections[start[j]].first = finish[j];
				connections[start[j]].second = 0;
				usedletters.insert(start[j]);
				usedletters.insert(finish[j]);
				if (start[j] == finish[j]) {
					alrset++;
				}
			}
			else if (connections[start[j]].first == finish[j]) {
				continue;
			}
			else {
				cond = 1;
				break;
			}
		}
		if (cond == 1) {
			cout << -1 << endl;
			continue;
		}
		int loopcount = 0;
		for (int j = 0; j < start.size(); j++) {
			if (connections[start[j]].second == 0) {
				stack<char>dfs;
				dfs.push(connections[start[j]].first);
				connections[start[j]].second = 1;
				while (dfs.size() != 0) {
					char current = dfs.top();
					dfs.pop();
					if (connections.count(current) != 0) {
						if (connections[current].second == 1 && current != connections[current].first) {
							loopcount++;
							break;
						}
						else if (connections[current].second != 1) {
							connections[current].second = 1;
							dfs.push(connections[current].first);
						}
					}
				}
			}
			if (connections[start[j]].second == 1) {
				continue;
			}
		}
		if (loopcount > 0) {
			cout << 1 + connections.size() - alrset << endl;
		}
		else {
			cout << connections.size() - alrset << endl;
		}
	}
}