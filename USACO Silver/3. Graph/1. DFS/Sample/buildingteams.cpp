#include <cstdio>
#include <vector>

const int MN = 1e5 + 10;

int N, M;
bool bad, vis[MN], group[MN];
std::vector<int> a[MN];

void dfs(int n = 1, bool g = 0)
{
	vis[n] = 1;
	group[n] = g;
	for (int u : a[n])
		if (vis[u])
		{
			if (group[u] == g)
				bad = 1;
		}
		else
			dfs(u, !g);
}
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0, u, v; i < M; ++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	for (int i = 1; !bad && i <= N; ++i)
		if (!vis[i])
			dfs(i);
	if (bad)
		printf("IMPOSSIBLE\n");
	else
		for (int i = 1; i <= N; ++i) printf("%d%c", group[i] + 1, " \n"[i == N]);
	return 0;
}