#include <bits/stdc++.h>
using namespace std;
// imax is value that is biggest and can not actually be exchanged for
int imax = 100000000;
int n;
// Stores the coins that can be exhanged for a value.
vector<int> coins;
int dp[100000000];
vector<int>choice;


// This is recurrsive function that calls find(sum-c) everytime
int find(int sum)
{
    // Base conditions , is sum < 0 return no possible else if sum == 0 return 0;
    if (sum < 0) return imax;
    if (sum == 0)  return 0;
    // If already calculated, return the value saved.
    if (dp[sum] != imax) return dp[sum];
    int ans = imax;
    // Check for every coin possible.
    int temp = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        int result = find(sum - coins[i]);
        if (result + 1 < ans) {
            temp = coins[i];
            ans = result + 1;
        }
        choice.push_back(temp);
    }
    
    // Save value and return it.
    dp[sum] = ans;
    return dp[sum];
}

int main() {
    for (int i = 0; i < 1000000; i++) dp[i] = imax;
    dp[0] = 0;
    n = 3;
   /* for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }*/
    coins = { 1,3,4,6,8 };
    int sum;
    sum = 25;
    cout << find(sum) << endl;
    for (auto it : choice) {
        cout << it << " ";
    }
    return 0;
}