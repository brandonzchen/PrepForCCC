

#include <bits/stdc++.h>
using namespace std;

int A[10000];

bool solve()
{
    int n = 8;
    //cin >> n;
    vector<int> vec{ 1,3,4,2,5,3,4,2 };
    vector<int> ans(n, -1);
    stack<int> st;
    /*   for (int i = 0; i < n; i++)
       {
           int x;
           cin >> x;
           vec.push_back(x);
       }*/
    for (int i = 0; i < n; i++)
    {   
        if (!st.empty() && vec[st.top()] <= vec[i]) {
            ans[i] = vec[st.top()];
            st.push(i);
        }
        else if (st.empty() || vec[st.top()] <= vec[i]) {
            st.push(i);
            
        }
        else
        {
            while (!st.empty() && vec[i] <= vec[st.top()])
            {
                st.pop();
            }
            ans[i] = vec[st.top()];
            st.push(i);
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return false;
}

int main() {
    int t = 1;
    //c/*in >> t;*/
    while (t--)
    {
        solve();
    }
    return 0;
}