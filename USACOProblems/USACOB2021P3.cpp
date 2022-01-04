#include <bits/stdc++.h>
#include <unordered_set>
#include <chrono>;
using namespace std;


bool checkAndMove(vector<vector<char>> &currentgrid, int& y, int& x) {
	if (currentgrid[y][x] == '.') {
		return true;
	}
	else {
		return false;
	}
}


void solve(int &sizeofgrid, int &numturns, set<vector<char>> &currmoves, const char &first, const char &second) {
	for (int k = 1; k <= sizeofgrid - 1; k++) {
		for (int h = 1; h <= sizeofgrid - 1; h++) {
			if (numturns == 1) {
				k = sizeofgrid - 1;
				h = sizeofgrid - 1;
			}
			if (numturns == 2) {
				h = sizeofgrid - 1;
			}
			vector<char>case2(105);
			fill_n(case2.begin(), k, first);
			fill_n(case2.begin() + k, h, second);
			fill_n(case2.begin() + k + h, sizeofgrid - 1 - k, first);
			fill_n(case2.begin() + h + sizeofgrid - 1, sizeofgrid - 1 - h, second);
			currmoves.insert(case2);
		}
	}
}

int main() {
	ifstream fin("1.in");
	int numbercases;
	fin >> numbercases;
	for (int i = 0; i < numbercases; i++) {
		int gridsize; fin >> gridsize;
		int numberturns; fin >> numberturns;
		vector<vector<char>>grid(gridsize);
		for (int j = 0; j < gridsize; j++) {
			for (int k = 0; k < gridsize; k++) {
				char current; fin >> current;
				grid[j].push_back(current);
			}
		}
	/*int numbercases; cin >> numbercases;
	for (int i = 0; i < numbercases; i++) {
		int gridsize; cin >> gridsize;
		int numberturns; cin >> numberturns;
		vector<vector<char>>grid(gridsize);
		for (int j = 0; j < gridsize; j++) {
			for (int k = 0; k < gridsize; k++) {
				char current; cin >> current;
				grid[j].push_back(current);
			}
		}*/

		int pathcount = 0;
		set<vector<char>>currentmoves;

		solve(gridsize, numberturns, currentmoves, 'r', 'd');
		solve(gridsize, numberturns, currentmoves, 'd', 'r');

		for (auto currentcase : currentmoves) {
			int condition1 = 0;
			int posx1 = 0; int posy1 = 0;
			for (auto currentchar : currentcase) {
				if (currentchar == 'r') {
					posx1++;
					if (checkAndMove(grid, posy1, posx1))continue;
					else { condition1 = 1; break; }
				}
				if (currentchar == 'd') {
					posy1++;
					if (checkAndMove(grid, posy1, posx1)) continue;
					else { condition1 = 1; break; }
				}
			}
			if (condition1 == 0) pathcount++;

		}
		cout << pathcount;
		cout << endl;
	}
}




		

