/*
Chapter 13: Shortest Paths Algorithm
Topic: Dijsktra's Algorithm
Implementation: O(nlog(n))
*/
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[100000];
int dis[100000];
bool vis[100000];

void dijsktra(int source)
{
    priority_queue<pair<int, int>> q;
    dis[source] = 0;
    q.push({ dis[source], source });
    while (!q.empty())
    {
        // Pop least distance element from the queue
        int a = q.top().second; q.pop();
        // If it is always processed then continue;
        if (vis[a]) continue;
        // Mark it processed that means now it have minimum possible distance
        vis[a] = true;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (dis[a] + w  < dis[b])
            {
                dis[b] = dis[a] + w;
                q.push({ -dis[b],b });
            }
        }
        
    }
}





int main() {
    /*
    Initialise all the variables
    */
  /*  for (int i = 0; i < 10000; i++)
    {
        dis[i] = INT_MAX;
        vis[i] = false;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({ y,w });
        adj[y].push_back({ x,w });
    }
    int source, dest;
    cin >> source >> dest;
    dijsktra(source);
    cout << dis[dest] << endl;
    return 0;*/
    ifstream fin("bellmanfordtest.txt");
    for (int i = 0; i < 10000; i++)
    {
        dis[i] = INT_MAX;
        vis[i] = false;
    }
    int n, m;
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        fin >> x >> y >> w;
        adj[x].push_back({ y,w });
        adj[y].push_back({ x,w });
    }
    int source, dest;
    fin >> source >> dest;
    dijsktra(source);
    cout << dis[dest] << endl;
    return 0;
}
