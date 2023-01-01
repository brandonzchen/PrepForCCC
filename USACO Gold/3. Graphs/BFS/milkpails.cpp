#include <bits/stdc++.h>

using namespace std;

bool vis[101][101][101];
int x, y, k, m, sol;

void floodfill(int curX, int curY, int curK) {
	if (vis[curX][curY][curK] || curK > k) return;
	vis[curX][curY][curK] = true;

	sol = min(sol, abs(m - (curX + curY)));

	floodfill(x, curY, curK + 1);
	floodfill(curX, y, curK + 1);

	floodfill(0, curY, curK + 1);
	floodfill(curX, 0, curK + 1);

	int leftoverX = (curX + curY > y ? curX + curY - y : 0);
	int leftoverY = (curY + curX > x ? curY + curX - x : 0);

	floodfill(leftoverX, min(y, curY + curX), curK + 1);
	floodfill(min(x, curX + curY), leftoverY, curK + 1);
}

int main() {
	ifstream cin ("pails.in");
	ifstream cout("pails.out");

	cin >> x >> y >> k >> m;
	sol = m;
	floodfill(0, 0, 0);
	cout << sol << endl;
}