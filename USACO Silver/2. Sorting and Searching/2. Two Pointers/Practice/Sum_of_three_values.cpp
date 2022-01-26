#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int main() {
	/*ifstream fin("USACO Silver/2. Sorting and Searching/2. Two Pointers/Practice/sumthreevaluestest.txt");*/
	int arrsize, target; 
	cin >> arrsize >> target;
	vector<int>numbers;
	vector<int>finalthree;
	vector<pi>numberscopy;
	for (int i = 0; i < arrsize; i++) {
		int temp; cin >> temp;
		numbers.push_back(temp);
		pi valinx;
		valinx = make_pair(temp, i);
		numberscopy.push_back(valinx);
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
	else{
		vector<int>indexs;
		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < numberscopy.size(); j++) {
				if (numberscopy[j].first == finalthree[i]) {
					if (count(indexs.begin(), indexs.end(), numberscopy[j].second)) {
						continue;
					}
					else {
						if (i != 2) {
							cout << numberscopy[j].second + 1 << " ";
							indexs.push_back(numberscopy[j].second);
							break;
						}
						else {
							cout << numberscopy[j].second + 1;
							indexs.push_back(numberscopy[j].second);
							break;
						}
						
					}
				}
			}

		}
	}

}