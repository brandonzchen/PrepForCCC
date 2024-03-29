#include <bits/stdc++.h>
using namespace std;

int N;
string S;

bool dups(int len){
    set<string> X;
    for (int i = 0; i <= N - len; i++) {
        if (X.count(S.substr(i, len)) > 0) return true;
        X.insert(S.substr(i, len));
    }
    return false;
}

int main(){
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    fin >> N >> S;
    int ans = 1;
    while (dups(ans)) ans++;
    fout << ans << endl;
    return 0;
}