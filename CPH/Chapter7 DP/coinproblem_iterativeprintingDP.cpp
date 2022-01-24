/*
Chapter 7 : Dynamic Programming
Topic : Coin Problem
Question : You are given coins of value coins[i] for all i that belong to n. Now find minimum coins to exchange for x.
This is iterative code for the same problem.
*/

#include <bits/stdc++.h>
using namespace std;
// imax is value that is biggest and can not actually be exchanged for
int imax = 100000000;
int n = 5;
// Stores the coins that can be exhanged for a value.
const int SIZE = 100;

vector<int> coins;
int dp[SIZE];
int choice[SIZE];

// This is iterative function that calls find(sum-c) everytime
int find(int sum)
{
    dp[0] = 0;
    choice[0] = 0;
    // First we build smaller solutions i.e 0 , 1 , 2 , 3 and then use them to find the greater solution.
    for (int i = 0; i <= sum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] < 0) continue;
            if (dp[i] > dp[i - coins[j]] + 1)
            {
                dp[i] = dp[i - coins[j]] + 1;
                choice[i] = coins[j];
            }
        }
    }
    return dp[sum];
}

int main() {
    for (int i = 0; i < SIZE; i++) dp[i] = imax;
    dp[0] = 0;
  /*  cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }*/
    //int sum;
    coins = { 1,3,4,6,8};
    int sum = 25;
 /*   cin >> sum;*/
    cout << find(sum) << endl;
    int curr = sum;
    cout << "Choice of coins:" << endl;
    while (curr > 0)
    {
        cout << choice[curr] << " ";
        curr -= choice[curr];
    }
    return 0;
}