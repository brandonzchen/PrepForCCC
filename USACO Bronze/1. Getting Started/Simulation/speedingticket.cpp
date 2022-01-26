#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int roadseg, bessieseg;
    cin >> roadseg >> bessieseg;
    vector <int>roadmax;
    vector <int>bessiespeed;
    int max = 0;
    for (int i = 0; i < roadseg; i++) {
        int length, speed;
        cin >> length >> speed;
        for (int j = 0; j < length; j++) {
            roadmax.push_back(speed);
        }
    }
    for (int a = 0; a < bessieseg; a++) {
        int length, speed;
        cin >> length >> speed;
        for (int b = 0; b < length; b++) {
            bessiespeed.push_back(speed);
        }
    }
    for (int c = 0; c < 100; c++) {
        if (bessiespeed[c] > roadmax[c]) {
            int temp = bessiespeed[c] - roadmax[c];
            if (temp > max) {
                max = temp;
            }
        }
    }
    cout << max;

}