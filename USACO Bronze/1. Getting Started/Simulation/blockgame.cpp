#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

	long long N;
	vector<int>letters(26, 0);
	cin >> N;
	string s1 = "abcdefghijklmnopqrstuvwxyz";
	string s2, s3;
	int s2counter = 0;
	int s3counter = 0;
	for (int i = 0; i < N; i++) {
		cin >> s2 >> s3;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < s2.size(); j++) {
				if (s2[j] == s1[i]) {
					s2counter += 1;
				}
			}
			for (int k = 0; k < s3.size(); k++) {
				if (s3[k] == s1[i]) {
					s3counter += 1;
				}
			}
			letters[i] += max(s2counter, s3counter);
			s2counter = 0;
			s3counter = 0;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << letters[i] << endl;
	}

}