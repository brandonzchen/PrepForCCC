#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> primes{1};
int primesindex[5000010];
bool prime[5000001];
int isprime(int num) {
    if (num <= 1)
        return 0;
    int square = sqrt(num);
    for (int i = 2; i <= square; i++) {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1; //if both failed then num is prime
}
int countPrimes(int strt, int end) {
    int count = 0;
    for (int i = strt; i <= end; i++) {
        if (isprime(i) == 1)
        {
            primesindex[i] = 1;
            primes.push_back(i);
            count++;
        }
    }
    return count;
}



void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p]) {
            primes.push_back(p);
            primesindex[p] = 1;
        }
 }





int main() {
    int n = 5000001;
    //countPrimes(2, 5000000);
    SieveOfEratosthenes(n);
    
    vector<int>lowestcows(5000001, 0);
    for (int j = 4; j <= 5000001; j ++) {
        if (j % 4 == 0) {
            lowestcows[j] = j / 2;
        }
        
    }
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        tuple<int, int, int> mincow{5000001, 5000001, 0};
        int rooms; cin >> rooms;
        for (int j = 0; j < rooms; j++) {
            int temp; cin >> temp;
            tuple<int, int, int> temp1{ 5000001, 5000001, 0 };
            if (lowestcows[temp] == 0) {
                auto low = upper_bound(primes.begin(), primes.end(), temp);
                int pointer = low - primes.begin() - 1;
            
                while (pointer != -1) {
                    if ((temp - primes[pointer]) % 4 == 0) {
                        lowestcows[temp] = lowestcows[temp - primes[pointer]] + 1;
                        break;
                    }
                    pointer--;
                }
                tuple<int, int, int> temp1{ lowestcows[temp], j , 0 };
                mincow = min(mincow, temp1);
            }
            else if (temp % 4 == 0) {
                tuple<int, int, int> temp1{ lowestcows[temp] + 1, j , 1};
                mincow = min(mincow, temp1);
            }
            if (temp % 4 != 0 && lowestcows[temp] != 0) {
                tuple<int, int, int> temp1{ lowestcows[temp], j , 0 };
                mincow = min(mincow, temp1);
            }
        }
        if (get<2>(mincow) ==  1) {
            cout << "Farmer Nhoj" << endl;
        }
        if (get<2>(mincow) == 0) {
            cout << "Farmer John" << endl;
        }
    }
}