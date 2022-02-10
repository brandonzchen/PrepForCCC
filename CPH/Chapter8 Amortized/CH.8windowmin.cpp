#include <bits/stdc++.h>
using namespace std;

int A[10000];
int n = 8;
int w = 4;
vector<int> vec = {2, 1, 4, 5, 3, 4, 1, 2};
vector<int> ans;

void solve()
{
    deque<int> deq;
    for (int i = 0; i < n; i++)
    {
        //if (deq.size() < w) {
        //    deq.push_back(vec[i]);
        //}
 /*        If size of window, deq.size() is greater then the given window size, start               decreasing window size.*/
        if (deq.size() + 1 > w)
        {
            deq.pop_front();
        }
        // If current element is less then the deque last element start poping them till dequeue last element is less than or equal to current element.
        if (deq.size() && deq.back() > vec[i])
        {
            while (deq.size() && deq.back() > vec[i]) deq.pop_back();
        }
        // Push current element.
        deq.push_back(vec[i]);
        if (deq.size()) deq.pop_back();
        ans.push_back(deq.front());
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--)
    {
        // This part involves inputs only. All these vectors and variables are made global so that I can separate main functionality in solve() function
        //vec.clear();
        //ans.clear();
        //cin >> n;
        //cin >> w;
        //for (int i = 0; i < n; i++)
        //{
        //    int x;
        //    cin >> x;
        //    vec.push_back(x);
        //}
        // Input ends, now solve the answer.
        solve();
    }
    return 0;
}