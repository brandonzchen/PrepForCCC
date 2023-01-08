#include <bits/stdc++.h>
using namespace std;

int dp[5][5];

string s1, s2;

int solve(int i, int j)
{
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i - 1] == s2[j - 1]) dp[i][j] = solve(i - 1, j - 1);
    else dp[i][j] = min(min(solve(i - 1, j), solve(i - 1, j - 1)), solve(i, j - 1)) + 1;
    return dp[i][j];
}

int main() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else dp[i][j] = -1;
        }
    s1 = "DESK";
    s2 = "KEY";
    cout << solve(s1.size(), s2.size()) << endl;
    return 0;
}