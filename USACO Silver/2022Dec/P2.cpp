//#include<bits/stdc++.h>
//using namespace std;
//using ll = long long;
//vector<int> primes{1};
//int primesindex[5000010];
//bool prime[5000000];
//
//
//int isprime(int num) {
//    if (num <= 1)
//        return 0;
//    int square = sqrt(num);
//    for (int i = 2; i <= square; i++) {
//        if (num % i == 0)
//        {
//            return 0;
//        }
//    }
//    return 1; //if both failed then num is prime
//}
//int countPrimes(int strt, int end) {
//    int count = 0;
//    for (int i = strt; i <= end; i++) {
//        if (isprime(i) == 1)
//        {
//            primesindex[i] = 1;
//            primes.push_back(i);
//            count++;
//        }
//    }
//    return count;
//}
//
//
//
//void SieveOfEratosthenes(int n)
//{
//    // Create a boolean array "prime[0..n]" and initialize
//    // all entries it as true. A value in prime[i] will
//    // finally be false if i is Not a prime, else true.
//
//    memset(prime, true, sizeof(prime));
//
//    for (int p = 2; p * p <= n; p++) {
//        // If prime[p] is not changed, then it is a prime
//        if (prime[p] == true) {
//            // Update all multiples of p greater than or
//            // equal to the square of it numbers which are
//            // multiple of p and are less than p^2 are
//            // already been marked.
//            for (int i = p * p; i <= n; i += p)
//                prime[i] = false;
//        }
//    }
//
//    // Print all prime numbers
//    for (int p = 2; p <= n; p++)
//        if (prime[p]) {
//            primes.push_back(p);
//            primesindex[p] = 1;
//        }
// }
//
//
//
//
//
//int main() {
//    //countPrimes(2, 5000000);
//    SieveOfEratosthenes(30);
//
//    vector<int>lowestcows(5000001, 0);
//    for (int j = 2; j <= 5000001; j++) {
//        if (j % 2 == 0) {
//            lowestcows[j] = j / 2;
//        }
//        
//    }
//    int testcases; cin >> testcases;
//    for (int i = 0; i < testcases; i++) {
//        int rooms; cin >> rooms;
//        int mincow = 5000001;
//        int condition = 2;
//        for (int j = 0; j < rooms; j++) {
//            int temp; cin >> temp;
//            if (temp % 2 != 0 && lowestcows[temp] != 0) {
//                if (lowestcows[temp] < mincow) {
//                    mincow = lowestcows[temp];
//                    condition = 0;
//                }
//                continue;
//            }
//            if (temp % 2 != 0) {
//                auto low = upper_bound(primes.begin(), primes.end(), temp);
//                int pointer = low - primes.begin() - 1;
//            
//                while (pointer != -1) {
//                    if ((temp - primes[pointer]) % 4 == 0) {
//                        lowestcows[temp] = lowestcows[temp - primes[pointer]] + 1;
//                        break;
//                    }
//                    pointer--;
//                }
//                if (lowestcows[temp] < mincow) {
//                    mincow = lowestcows[temp];
//                    condition = 0;
//                }
//            }
//            else if (temp % 4 == 0) {
//                if (lowestcows[temp] + 1 < mincow) {
//                    mincow = lowestcows[temp] + 1;
//                    condition = 1;
//                }
//            }
//            else if (temp % 2 == 0 && temp % 4 != 0) {
//                if (lowestcows[temp] < mincow) {
//                    mincow = lowestcows[temp];
//                    condition = 0;
//                }
//            }
//            
//        }
//        if (condition ==  1) {
//            cout << "Farmer Nhoj" << endl;
//        }
//        if (condition == 0) {
//            cout << "Farmer John" << endl;
//        }
//    }
//}

#include <iostream>
using namespace std;

const int mx = 5000005;
int min_turns[mx] = { 0, 1 };
bool composite[mx] = { false };
int max_mod4[4] = { 2, 1, 2, 3 };

int main() {
	for (int i = 2; i < mx; i++) {
		if (!composite[i]) {
			for (int j = i; j < mx; j += i) {
				composite[j] = true;
			}
			max_mod4[i % 4] = i;
		}
		min_turns[i] = (i - max_mod4[i % 4]) / 2 + 1;
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = mx;
		for (int i = 0; i < n; i++) {
			int a_i; cin >> a_i;
			if (min_turns[a_i] / 2 < ans / 2) ans = min_turns[a_i];
		}
		if (ans & 1) cout << "Farmer John" << endl;
		else cout << "Farmer Nhoj" << endl;
	}
}