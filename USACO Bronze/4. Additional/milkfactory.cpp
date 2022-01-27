#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>>links;
int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
	int fac; cin >> fac;
    int condition = 0;

	for (int i = 0; i < fac - 1; i++) {
		int first, second; cin >> first >> second;
		pair<int, int> temp;
		temp = make_pair(second, first);
        links.push_back(temp);
	}
	sort(links.begin(), links.end());
    for (int i = 0; i < fac; i++) {
        set<pair<int, int>>totals;
        stack<int>dfs;
        for (int j = 0; j < links.size(); j++) {
            if (links[j].first == i) {
                totals.insert(links[j]);
                dfs.push(links[j].second);
            }
        }
        while (dfs.size() != 0) {
            int current = dfs.top();
            dfs.pop();
            for (int k = 0; k < links.size(); k++) {
                if (links[k].first == current) {
                    pair<int, int>temp1;
                    temp1 = make_pair(i, links[k].second);
                    totals.insert(temp1);
                    dfs.push(links[k].second);
                }
            }
        }
        if (totals.size() == fac - 1) {
            condition = 1;
            cout << i;
            break;
        }

    }
    if (condition == 0) {
        cout << -1;
    }
	
}

