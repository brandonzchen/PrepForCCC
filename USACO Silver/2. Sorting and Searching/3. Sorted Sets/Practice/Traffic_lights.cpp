#include <bits/stdc++.h>
using namespace std;

int main() {
	//ifstream cin("USACOProblems/Silver/Practice Problems/trafficlightstest.txt");
	int length, lights;
	cin >> length >> lights;
	multiset<int>differences;
	differences.insert(0);
	differences.insert(length);
	set<int>trafficlights;
	trafficlights.insert(0);
	trafficlights.insert(length);
	for (int i = 0; i < lights; i++) {
		int current;cin >> current;
		auto temp = trafficlights.lower_bound(current);
		auto biggerthan = temp;
		auto lessthan = --temp;
		int difference = *biggerthan - *lessthan;
		int rightdistance = *biggerthan - current;
		int leftdistance = current - *lessthan;
		differences.erase(differences.find(difference));
		differences.insert(rightdistance);
		differences.insert(leftdistance);
		trafficlights.insert(current);
		auto end = differences.end();
		end--;
		cout << *end << endl ;
	}

}


