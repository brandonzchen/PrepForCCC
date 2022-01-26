#include <bits/stdc++.h>
using namespace std;

const int mxn = 50;
int n, w[mxn * 2];

int main() {
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    sort(w, w + n);
    int ans = 50000;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<int> x;
            for (int k = 0; k < n; ++k)
                if (k != i && k != j)
                    x.push_back(w[k]);
            int curr = 0;
            for (int k = 0; k < n - 2; k += 2)
                curr += x[k + 1] - x[k];
            ans = min(ans, curr);
        }
    }
    cout << ans;
}