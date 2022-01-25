#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll totalSum;
int main(){
	/*ifstream fin("USACOProblems/Silver/Practice Problems/arraydivisiontest.txt");*/
	vector<int> A;
	int numbers, groups;
	cin >> numbers >> groups;
	A.resize(numbers);
	for (int i = 0; i < numbers; ++i) {
		cin >> A[i];
		totalSum += A[i];
	}
	ll lowest = 1, highest = totalSum;
	while (lowest < highest) {
		ll max = lowest + (highest - lowest) / 2;
		int i = 0, j = 0;
		ll sum;
		for (int x = 0; i < numbers && x < groups; i = j, x++) {
			sum = 0;
			while (j < numbers && sum + A[j] <= max) {
				sum += A[j++];
			}
		}
		if (i == numbers) {
			highest = max;
		}
		else {
			lowest = max + 1;
		}
	}
	cout << lowest;
}