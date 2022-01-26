#include <bits/stdc++.h>
using namespace std;

int N;
map<string, int> cows;
vector<pair<int, string>> v;

int main() {

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    cin >> N;
    string cow;
    int n;
    for (int i = 0; i < N; ++i) {
        cin >> cow >> n;
        cows[cow] += n;
    }

    for (pair<string, int> p : cows)
        v.push_back({ p.second, p.first });

    sort(v.begin(), v.end());

    int index = 0;

    if (v.size() == 7)
        while (index < 7 && v[index].first == v[0].first) ++index;

    if (index < v.size() && (index + 1 == v.size() || v[index].first != v[index + 1].first)) { 
        cout << v[index].second;
        return 0;
    }
    cout << "Tie";

}