#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("2018JanP2test.txt", "r", stdin);
	// the following line creates/overwrites the output file
	/*freopen("problemname.out", "w", stdout);*/

	// cin now reads from the input file instead of standard input
	int a;
	int b;
	int c;
	cin >> a >> b >> c;

	// cout now prints to the output file instead of standard output
	cout << "The sum of these three numbers is " << a << " " <<  b << " " << c << "\n";
}