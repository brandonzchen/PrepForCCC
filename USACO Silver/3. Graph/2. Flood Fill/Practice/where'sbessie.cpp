#include <bits/stdc++.h>
using namespace std;

//ifstream cin("where.in");
//ofstream cout("where.out");

int N, x, y, a, b;
int grid[20][20];
bool visited[20][20];
vector<tuple<int, int, int, int>> answers; //x1, y1, x2, y2

void flood_fill(int cx, int cy, int c) {
	if (cx < x || cx > a || cy < y || cy > b) return;
	if (visited[cy][cx] || grid[cy][cx] != c) return;
	visited[cy][cx] = true;
	flood_fill(cx - 1, cy, c);
	flood_fill(cx + 1, cy, c);
	flood_fill(cx, cy - 1, c);
	flood_fill(cx, cy + 1, c);
}

bool is_pcl(int x1, int y1, int x2, int y2) {
	map<int, int> colors;
	int areas = 0;
	x = x1;
	y = y1;
	a = x2;
	b = y2;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			visited[j][i] = 0;
		}
	}

	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (!visited[j][i]) {
				flood_fill(i, j, grid[j][i]);
				areas++;
				colors[grid[j][i]]++;
				if (colors.size() > 2) return false;
			}
		}
	}

	int cnt = 0;
	for (auto color : colors)
		if (color.second > 1)
			cnt++;

	if (cnt > 1) return false;
	return (areas >= 3 && colors.size() == 2);
}

bool inside(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	bool f = get<0>(a) >= get<0>(b) && get<2>(a) <= get<2>(b);
	bool s = get<1>(a) >= get<1>(b) && get<3>(a) <= get<3>(b);

	return (f && s);
}

bool check(tuple<int, int, int, int> a) {
	for (auto each : answers)
		if (inside(a, each))
			return false;
	return true;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char a;
			cin >> a;
			grid[j][i] = a - 'A';
		}
	}

	for (int hl = N; hl >= 0; hl--) {
		for (int vl = N; vl >= 0; vl--) {
			for (int x = 0; x < N; x++) {
				for (int y = 0; y < N; y++) {
					tuple<int, int, int, int> curr = make_tuple(x, y, x + hl, y + vl);
					if (x + hl >= N || y + vl >= N) continue;
					else if (check(curr) && is_pcl(x, y, x + hl, y + vl)) {
						answers.push_back(curr);
					}
				}
			}
		}
	}

	cout << answers.size() << endl;
}