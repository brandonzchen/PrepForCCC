/*
Chapter 13: Shortest Paths
Bellman Ford Algorithm
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge
{
    int a;
    int b;
    int w;
    edge(int x, int y, int z)
    {
        a = x;
        b = y;
        w = z;
    }
};
vector<edge> edges;
int dis[10000];

void bellmanford(int source, int target)
{
    dis[source] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dis[edges[j].a] + edges[j].w < dis[edges[j].b])
            {
                dis[edges[j].b] = min(dis[edges[j].a] + edges[j].w, dis[edges[j].b]);
            }
        }
    }
}

int main() {
    /*for (int i = 0; i < 1000; i++) dis[i] = INT_MAX;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge x(a, b, w);
        edges.push_back(x);
    }
    int x, y;
    cin >> x >> y;
    bellmanford(x, y);
    cout << dis[y] << " ";
    return 0;*/
    ifstream fin("bellmanfordtest.txt");
    for (int i = 0; i < 1000; i++) dis[i] = INT_MAX;
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        fin >> a >> b >> w;
        edge x(a, b, w);
        edges.push_back(x);
    }
    int x, y;
    fin >> x >> y;
    bellmanford(x, y);
    cout << dis[y] << " ";
    return 0;
}