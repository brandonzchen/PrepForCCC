#include <bits/stdc++.h>
using namespace std;

int A[100];
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A, A + n);
    int x = A[(n - 1) / 2];
    cout << x << endl;
}

int main() {
    solve();
    return 0;
}   