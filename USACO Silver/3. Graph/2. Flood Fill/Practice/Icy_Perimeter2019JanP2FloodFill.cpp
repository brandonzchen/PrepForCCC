#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1005;

char grid[MAXN][MAXN];
int n;
bool visited[MAXN][MAXN];
ll currA = 0;
ll currP = 0;
ll area = 0;
ll perimeter = 0;


void floodfill(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) {
		currP++;
		return;
	}
	if (visited[r][c]) return;
	if (grid[r][c] == '.') {
		currP++;
		return;
	}
	visited[r][c] = true;
	if (grid[r][c] == '#') {
		currA++;
	}
	floodfill(r, c + 1);
	floodfill(r, c - 1);
	floodfill(r - 1, c);
	floodfill(r + 1, c);
}

int main() {
	ifstream fin("perimeter.in");
	ofstream fout("perimeter.out");
	fin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> grid[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && grid[i][j] == '#') {
				floodfill(i, j);
				if (area == currA) {
					perimeter = min(perimeter, currP);
				}
				else if (currA > area) {
					area = currA;
					perimeter = currP;
				}
				currA = currP = 0;
			}
		}
	}
	cout << area << " " << perimeter << endl;
	return 0;
}