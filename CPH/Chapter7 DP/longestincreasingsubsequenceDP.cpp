/*
    Longest Increasing Subsequence.
    You are given an array of size n, find the longest increasing subsequence.
*/
#include <bits/stdc++.h>
using namespace std;

int lis[1000001];
int A[100000];
int n;


// Function that returns the max answer.
int solve()
{
    int ans = 0;
    // O(n^2) loop for checking the max LIS
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            // If this element is less then current ith element, then A[j] < A[i] is a sequence including the sequence having last element as A[j]
            if (A[j] < A[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
        ans = max(ans, lis[i]);
    }
    return ans;
}

int main() {
    for (int i = 0; i < 1000001; i++)
        lis[i] = 1;
    n = 100000;
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 10000;
    }
    /*int A[8] = { 6, 2, 5, 1, 7, 4, 8, 3 };*/
    cout << solve() << endl;
    return 0;
}