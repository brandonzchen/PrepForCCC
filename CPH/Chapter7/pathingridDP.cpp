#include <bits/stdc++.h>
using namespace std;

int A[1000][1000];
int dp[1000][1000];
int n;

long long solve()
{   // Notice the traversal, starting from 0,0 , you goto every x,y and check if
    // moving to x,y is more profitable from x-1,y or x,y-1 and make the choice
    // Thus every x,y have maximum value that can be collected from moving from 0,0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0) dp[i][j] = A[i][j];
            else if (i == 0)
            {
                dp[i][j] = A[i][j] + dp[i][j - 1];
            }
            else if (j == 0)
            {
                dp[i][j] = A[i][j] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + A[i][j];
            }
        }
    }
    // Return the max value that can be obtained at n-1,n-1
    return dp[n - 1][n - 1];
}


int main() {
    // Input and Initialisation
    //cin >> n;
    //for (int i = 0; i < n; i++)
    //    for (int j = 0; j < n; j++)
    //    {
    //        dp[i][j] = -1;
    //        A[i][j] = 0;
    //    }
    //for (int i = 0; i < n; i++)
    //    for (int j = 0; j < n; j++)
    //        cin >> A[i][j];

    /*ifstream fin("pathingridtest.txt");
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
            A[i][j] = 0;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> A[i][j];*/

    n = 7;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
            A[i][j] = 0;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = rand()%10;
    // Call out the solver
    cout << solve() << endl;
    return 0;
}