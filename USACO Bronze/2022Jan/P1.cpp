#include <bits/stdc++.h>
using namespace std;
using vc = vector<char>;
vector<vc>correct;
vector<vc>guess;
vector<char>cletters;
int green = 0, yellow = 0;
int main() {

    for (int i = 0; i < 3; i++) {
        char a, b, c; cin >> a >> b >> c;
        vc temp{ a, b, c };
        correct.push_back(temp);
        cletters.push_back(a);
        cletters.push_back(b);
        cletters.push_back(c);
    }
    for (int i = 0; i < 3; i++) {
        char a, b, c; cin >> a >> b >> c;
        vc temp1{ a, b, c };
        guess.push_back(temp1);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (correct[i][j] == guess[i][j]) {
                green++;
                auto it = find(cletters.begin(), cletters.end(), correct[i][j]);
                cletters.erase(it);
            }
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (correct[i][j] != guess[i][j]) {
                if (count(cletters.begin(), cletters.end(), guess[i][j])) {
                    auto it = find(cletters.begin(), cletters.end(), guess[i][j]);
                    cletters.erase(it);
                    yellow++;
                }        
            }
        }
    }
    cout << green << endl << yellow;

 }