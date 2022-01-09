#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool sorty(pair<int, int>& firsty, pair<int, int>& secondy) {
	return(firsty.second < secondy.second);
}

ll minmaxcalcadd(vector<pair<int, int>> &sorting, pair<int, int>newcoord,ll &max, ll &min, char s) {
	ll minx, end, maxx;
	if (s == 'x')
	{
		minx = sorting[0].first;
		end = sorting.size() - 1;
		maxx = sorting[end].first;
	}
	else
	{
		minx = sorting[0].second;
		end = sorting.size() - 1;
		maxx = sorting[end].second;
	}
	if (newcoord.second > max) max = newcoord.second;
	if (newcoord.second < min) min = newcoord.second;

	return (maxx - minx) * (max - min);
}


ll minmaxcalcsubtract(vector<pair<int, int>>& sorting, pair<int, int>delcoord, ll& max, ll& min, char s) {
	ll minx, end, maxx;
	if (s == 'x')
	{
		minx = sorting[0].first;
		end = sorting.size() - 1;
		maxx = sorting[end].first;
	}
	else
	{
		minx = sorting[0].second;
		end = sorting.size() - 1;
		maxx = sorting[end].second;
	}
	if (delcoord.second == max) {
		for (auto it : sorting) {
			if (it.second > max) max = it.second;
		}
	}
	if (delcoord.second == min) {
		min = sorting[0].second;
		for (auto it : sorting) {
			if (it.second < min) min = it.second;
		}
	}
	return (maxx - minx) * (max - min);
}

//ll minmaxcalcy(vector<pair<int, int>> &sorting, pair<int, int>delcoord, ll max, ll min) {
//
//	ll miny = sorting[0].second;
//	ll end = sorting.size() - 1;
//	ll maxy = sorting[end].second;
//	ll minx = 1000000000;
//	ll maxx = 0;
//
//	//sort(sorting.begin(), sorting.end());
//	//int minx = sorting[0].first;
//	//int end1 = sorting.size() - 1;
//	//int maxx = sorting[end1].first;
//
//	if (maxx != minx && maxy != miny) {
//		return (maxx - minx) * (maxy - miny);
//	}
//	else if (maxx == minx && maxy != miny) {
//		return 0;
//	}
//	else if (maxx != minx && maxy == miny) {
//		return 0;
//	}
//	else {
//		return 0;
//	}
//}
vector < pair< int, int > > sortedbyy ;
vector < pair< int, int > > sortedbyx ;

int main(){
	/*ifstream fin("USACOProblems/Silver/Practice Problems/splittingthefields.txt");*/
	ifstream fin("split.in");
	ofstream fout("split.out");
	ll optimal = 0;
	int cows;
	fin >> cows;
	for (int i = 0; i < cows; i++) {
		int temp1, temp2; fin >> temp1 >> temp2;
		pair<int, int> tempcoords;
		tempcoords.first = temp1;
		tempcoords.second = temp2;
		sortedbyx.push_back(tempcoords);
		sortedbyy.push_back(tempcoords);
	}

	sort(sortedbyx.begin(), sortedbyx.end());
	vector < pair< int, int > > firstcoords{ sortedbyx[0]};
	vector < pair< int, int > > secondcoords;
	secondcoords = sortedbyx;
	secondcoords.erase(secondcoords.begin());
	ll globalminyfirst = firstcoords[0].second;
	ll globalmaxyfirst = firstcoords[0].second;
	ll globalminysecond = secondcoords[0].second;
	ll globalmaxysecond = secondcoords[0].second;
	ll x = 0, y = 10000000;
	pair<int, int>test = { sortedbyx[0].first, sortedbyx[0].second };
	ll initial = 143;
	for (auto it : secondcoords) {
		if (it.second > globalmaxysecond) globalmaxysecond = it.second;
		if (it.second < globalminysecond) globalminysecond = it.second;
	}
	for (int i = 1; i < cows - 1; i++) {
		pair<int, int> deleted = secondcoords[0];
		firstcoords.push_back(sortedbyx[i]);
		secondcoords.erase(secondcoords.begin());
		ll first = minmaxcalcadd(firstcoords, sortedbyx[i], globalmaxyfirst, globalminyfirst, 'x');
		ll second = minmaxcalcsubtract(secondcoords, deleted, globalmaxysecond, globalminysecond, 'x');
		ll newarea = first + second;
		if (initial - newarea > optimal && initial - newarea > 0)
		{
			optimal = initial - newarea;
			//cout << newarea;
		}
	}

	sort(sortedbyy.begin(), sortedbyy.end(),sorty);
	pair<int, int>testy = { sortedbyy[0].first, sortedbyy[0].second };
	ll initialy = 143;
	vector < pair< int, int > > firstcoordsy{ sortedbyy[0] };
	vector < pair< int, int > > secondcoordsy;
	secondcoordsy = sortedbyy;
	secondcoordsy.erase(secondcoordsy.begin());
	ll globalminxfirst = firstcoordsy[0].first;
	ll globalmaxxfirst = firstcoordsy[0].first;
	ll globalminxsecond = secondcoordsy[0].first;
	ll globalmaxxsecond = secondcoordsy[0].first;
	for (auto it : secondcoordsy) {
		if (it.first > globalmaxxsecond) globalmaxxsecond = it.first;
		if (it.first < globalminxsecond) globalminxsecond = it.first;
	}
	for (int i = 1; i < cows - 1; i++) {
		pair <int, int> deletedy = secondcoordsy[0];
		firstcoordsy.push_back(sortedbyy[i]);
		secondcoordsy.erase(secondcoordsy.begin());
		ll firsty = minmaxcalcadd(firstcoordsy, sortedbyy[i], globalmaxxfirst, globalminxfirst, 'y');
		ll secondy = minmaxcalcsubtract(secondcoordsy, deletedy, globalmaxxsecond, globalminxsecond, 'y');
		ll newareay = firsty + secondy;
		if (initialy - newareay > optimal && initialy - newareay > 0)
		{
			optimal = initial - newareay;
			//cout << newareay;
		}
	}
	


	fout << optimal;
	return 0;

}