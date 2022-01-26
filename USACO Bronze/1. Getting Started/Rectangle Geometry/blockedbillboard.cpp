#include <bits/stdc++.h>
using namespace std;

struct Rect {
	int x1, y1, x2, y2;
	int area() { 
		return (y2 - y1) * (x2 - x1);
	}
};

bool corner_covered(int x, int y, Rect rec) {
	return x >= rec.x1 && x <= rec.x2 && y >= rec.y1 && y <= rec.y2;
}

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	Rect a, b;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

	int corners_covered = 0;
	corners_covered += corner_covered(a.x1, a.y1, b);
	corners_covered += corner_covered(a.x1, a.y2, b);
	corners_covered += corner_covered(a.x2, a.y1, b);
	corners_covered += corner_covered(a.x2, a.y2, b);

	if (corners_covered == 4) {
		cout << 0;
	}
	else if (corners_covered < 2) {
		cout << a.area();
	}
	else {
		int overlap = (min(a.x2, b.x2) - max(a.x1, b.x1)) * (min(a.y2, b.y2) - max(a.y1, b.y1));
		cout << a.area() - overlap;
	}
}