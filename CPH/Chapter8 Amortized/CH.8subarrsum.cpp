#include <bits/stdc++.h>
using namespace std;

int A[8] = {2,3,2,5,2,5,2,3};

bool solve()
{
    int n = 8;
    //cin >> n;
    int x = 8;
    //cin >> x;
    //for (int i = 0; i < n; i++) cin >> A[i];
    // Starting pointer that moves from left.
    int st = 0;
    int csum = 0;
    // Second pointer is i, that tells the right extreme.
    for (int i = 0; i < n; i++)
    {
        csum += A[i];
        if (csum > x)
        {
            while (csum > x && st <= i)
            {
                csum -= A[st];
                st++;
            }
        }
        if (csum == x) return true;
    }
    return false;
}

bool findsum() 
{
    int arrsize = 8;
    int target = 1;
    int firstp = 0;
    int sum = 0;
    for (int i = 0; i < arrsize; i++) {
        if (sum == target) return true;
        if (sum + A[i] < target) {
            sum += A[i];
        }
        else  {
            while (sum + A[i] > target) {
                sum -= A[firstp];
                firstp++;
            }
            sum += A[i];
            
        }
    }
    return false;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--)
    {
        if (findsum())
        {
            cout << "Yes, exists" << endl;
        }
        else cout << "No, Subarray do not exist" << endl;
    }
    return 0;
}
