#include <bits/stdc++.h>
using namespace std;


bool checkPrime(int n, int k = 2) {
	if (n % k == 0) {
		return false;
	}
	if (k > floor(sqrt(k))) {
		return true;
	}
	if (n <= 2) {
		return (n == 2) ? true : false;
	}

	checkPrime(n, k + 1);

}

int main() {
	int x = 80;
	cout << (checkPrime(x) ? "yes" : "no");

}