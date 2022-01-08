#include <bits/stdc++.h>
using namespace std;

int main() {
	/*ifstream fin("USACOProblems/Silver/Practice Problems/sumthreevaluestest.txt");*/
	int arrsize, target; 
	cin >> arrsize >> target;
	vector<int>numbers;
	vector<int>finalthree;
	vector<int>numberscopy;
	for (int i = 0; i < arrsize; i++) {
		int temp; cin >> temp;
		numbers.push_back(temp);
		numberscopy.push_back(temp);
	}
	
	sort(numbers.begin(), numbers.end());
	for (int j = 0; j < arrsize - 1; j++) {
		if (finalthree.size() == 3) break;
		int temptarget = target - numbers[j];
		int pointer1 = j + 1;
		int pointer2 = arrsize - 1;
		while (temptarget != 0){
			if (pointer1 == pointer2) break;
			else if (numbers[pointer1] + numbers[pointer2] > temptarget) pointer2--;
			else if (numbers[pointer1] + numbers[pointer2] < temptarget) pointer1++;
			else if (numbers[pointer1] + numbers[pointer2] == temptarget) {
				temptarget -= numbers[pointer1] + numbers[pointer2];
				finalthree.push_back(numbers[pointer1]);
				finalthree.push_back(numbers[pointer2]);
				finalthree.push_back(numbers[j]);
			}
		}
		
	}
	if (finalthree.size() == 0) {
		cout << "IMPOSSIBLE";
	}
	else
	{
		for (auto i : finalthree) {
			int fix = 0;
			auto temp = find(numberscopy.begin(), numberscopy.end(), i);
			cout << distance(numberscopy.begin(), temp) + 1 + fix;
			cout << endl;

		}
	}

}