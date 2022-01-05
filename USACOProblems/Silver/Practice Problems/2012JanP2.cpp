
#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin("USACOProblems/Silver/Practice Problems/2012Janp2test.txt");
	int hay, instructions; fin >> hay >> instructions;

	vector<int> list(hay + 1);
	for (int i = 0; i < instructions; i++) {
		int temp1, temp2; fin >> temp1 >> temp2;
		temp1--;
		temp2--;
			
		list[temp1]++;
		list[temp2 + 1]--;
	}
	for (int i = 1; i < list.size(); i++){
		list[i] += list[i - 1];
	}
	sort(list.begin(), list.end());
	cout << list[hay/ 2 + 1] << endl;
}