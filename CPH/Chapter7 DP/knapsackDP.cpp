#include <bits/stdc++.h>
using namespace std;

int n;
int W[10000];
int dp[1000];
int sum = 0;

// Set dp[i][j] = 1 if sum j can be formed using i objects
//void solve()
//{
//    dp[0][0] = 1;
//    for (int j = 1; j <= n; j++)
//    {
//        for (int i = 0; i <= sum; i++)
//        {
//            if (i - W[j - 1] < 0)
//            {
//                // If weight of i was possible using j objects set it equal to 1
//                dp[j][i] = dp[j - 1][i];
//                continue;
//            }
//            // If weight of i was possible before without using jth object 
//            // Or if weight of i-W[j-1] was possible and adding current weight gives i
//            dp[j][i] = dp[j - 1][i - W[j - 1]] | dp[j - 1][i];
//        }
//    }
//}

void oneDSolve() {
    dp[0] = 1;
    for (int k = 1; k <= n; k++) {
        for (int x = sum; x >= 0; x--) {
            if (dp[x]) dp[x + W[k]] = 1;
        }
    }


}

int main() {
    // Input and Initialisation
    //cin >> n;
    //for (int i = 0; i < n; i++)
    //{
    //    cin >> W[i];
    //    sum += W[i];
    //}
    ifstream fin("knapsacktest.txt");
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> W[i];
        sum += W[i];
    }
    for (int i = 0; i <= sum; i++)
    {
        
        dp[i] = 0;

    }
    // Call out the solver
    oneDSolve();

    for (int i = 0; i <= sum; i++)
        if (dp[i]) cout << i << " ";
    return 0;
}