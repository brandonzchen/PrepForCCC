#include <bits/stdc++.h>
using namespace std;

int A[8] = {5,1,4,6,7,9,9,10};

bool solve()
{
    int n = 8;
    //cin >> n;
    int x = 12;
    //cin >> x;
    /*for (int i = 0; i < n; i++) cin >> A[i];*/
    //Sort so that we know that larger number is at right and smaller at left.
    sort(A, A + n);
    int i = 0; int j = n - 1;
    // Here we consider two pointer first at left and second at right. Then we start.
    // If sum > x, then reduce the larger number that is at right (j).
    // Else if sum < x then increase larger number that is at left (i).
    while (i < j)
    {
        if (A[i] + A[j] > x)
        {
            j--;
        }
        else if (A[i] + A[j] < x)
        {
            i++;
        }
        else
        {
            cout << i << " " << j << endl;
            cout << A[i] << " " << A[j];

            return true;
        }
    }
    return false;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--)
    {
        if (solve())
        {
            cout << "Yes, exists" << endl;
        }
        else cout << "No, do not exist" << endl;
    }
    return 0;
}