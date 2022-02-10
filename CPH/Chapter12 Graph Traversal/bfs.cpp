/*
Chapter 12: Graph Traversal
Topic: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;

// Adjacency list , lets suppose nodes are less then 1000
vector<int> adj[1000];
vector<bool> vis(1000, 0);
int dis[7];

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    dis[x] = 0;
    vis[x] = true;
    while (!q.empty())
    {
        int y = q.front();
        q.pop();

        for (auto u : adj[y])
        {
            if (vis[u]) continue;
            vis[u] = true;
            q.push(u);
            dis[u] = dis[y] + 1;
        }
    }
}


int main() {
    int n;
    cin >> n;
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "Disconnected Graph" << endl;
            return 0;
        }
    }
    cout << "Connected Graph" << endl;
    for (auto i : dis) {
        cout << i << endl;
    }
    return 0;
}
