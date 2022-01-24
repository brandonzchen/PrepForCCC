#include <bits/stdc++.h>
using namespace std;

int coins[4] = { 1, 2, 5, 10 };
void solve()
{
    int n = 7;
    int ans = 0;
    for (int i = 3; i >= 0; i--)
    {
        ans += n / coins[i];
        n %= coins[i];
    }
    cout << ans << endl;
}

int main()
{
    solve();
}