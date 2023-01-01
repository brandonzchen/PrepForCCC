//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//bool sorty(pair<int, int>& firsty, pair<int, int>& secondy) {
//	return(firsty.second < secondy.second);
//}
//
//ll minmaxcalcadd(vector<pair<int, int>> &sorting, pair<int, int>newcoord,ll &max, ll &min, char s) {
//	ll minx, end, maxx;
//	if (s == 'x')
//	{
//		minx = sorting[0].first;
//		end = sorting.size() - 1;
//		maxx = sorting[end].first;
//	}
//	else
//	{
//		minx = sorting[0].second;
//		end = sorting.size() - 1;
//		maxx = sorting[end].second;
//	}
//	if (newcoord.second > max) max = newcoord.second;
//	if (newcoord.second < min) min = newcoord.second;
//
//	return (maxx - minx) * (max - min);
//}
//
//
//ll minmaxcalcsubtract(vector<pair<int, int>>& sorting, pair<int, int>delcoord, ll& max, ll& min, char s) {
//	ll minx, end, maxx;
//	if (s == 'x')
//	{
//		minx = sorting[0].first;
//		end = sorting.size() - 1;
//		maxx = sorting[end].first;
//	}
//	else
//	{
//		minx = sorting[0].second;
//		end = sorting.size() - 1;
//		maxx = sorting[end].second;
//	}
//	if (delcoord.second == max) {
//		for (auto it : sorting) {
//			if (it.second > max) max = it.second;
//		}
//	}
//	if (delcoord.second == min) {
//		min = sorting[0].second;
//		for (auto it : sorting) {
//			if (it.second < min) min = it.second;
//		}
//	}
//	return (maxx - minx) * (max - min);
//}
//
//vector < pair< int, int > > sortedbyy ;
//vector < pair< int, int > > sortedbyx ;
//vector <pair<int, int>> original;
//
//
//int main(){
////	ifstream fin("USACOProblems/Silver/Practice Problems/splittingthefields.txt");
//	ifstream fin("split.in");
//	ofstream fout("split.out");
//	ll optimal = 0;
//	int cows;
//	fin >> cows;
//	for (int i = 0; i < cows; i++) {
//		int temp1, temp2; fin >> temp1 >> temp2;
//		pair<int, int> tempcoords;
//		tempcoords.first = temp1;
//		tempcoords.second = temp2;
//		sortedbyx.push_back(tempcoords);
//		sortedbyy.push_back(tempcoords);
//		original.push_back(tempcoords);
//	}
//
//	sort(sortedbyx.begin(), sortedbyx.end());
//	vector < pair< int, int > > firstcoords{sortedbyx[0]};
//	vector < pair< int, int > > secondcoords;
//	secondcoords = sortedbyx;
//	secondcoords.erase(secondcoords.begin());
//	ll globalminyfirst = firstcoords[0].second;
//	ll globalmaxyfirst = firstcoords[0].second;
//	ll globalminysecond = secondcoords[0].second;
//	ll globalmaxysecond = secondcoords[0].second;
//	ll totalminy = sortedbyx[0].second, totalmaxy = sortedbyx[0].second;
//	pair<int, int>test = { 0, sortedbyx[0].second};
//	for (auto it : secondcoords) {
//		if (it.second > globalmaxysecond) globalmaxysecond = it.second;
//		if (it.second < globalminysecond) globalminysecond = it.second;
//	}
//	for (auto it : sortedbyx) {
//		if (it.second > totalmaxy) totalmaxy = it.second;
//		if (it.second < totalminy) totalminy = it.second;
//	}
//	ll initial = minmaxcalcadd(sortedbyx, test, totalmaxy, totalminy, 'x');
//	
//	for (int i = 1; i < cows - 1; i++) {
//		pair<int, int> deleted = secondcoords[0];
//		firstcoords.push_back(sortedbyx[i]);
//		secondcoords.erase(secondcoords.begin());
//		ll first = minmaxcalcadd(firstcoords, sortedbyx[i], globalmaxyfirst, globalminyfirst, 'x');
//		ll second = minmaxcalcsubtract(secondcoords, deleted, globalmaxysecond, globalminysecond, 'x');
//		ll newarea = first + second;
//		if (initial - newarea > optimal && initial - newarea > 0)
//		{
//			optimal = initial - newarea;
//		}
//	}
//
//	sort(sortedbyy.begin(), sortedbyy.end(),sorty);
//	pair<int, int>testy = { sortedbyy[0].first, sortedbyy[0].second };
//	vector < pair< int, int > > firstcoordsy{ sortedbyy[0] };
//	vector < pair< int, int > > secondcoordsy;
//	secondcoordsy = sortedbyy;
//	secondcoordsy.erase(secondcoordsy.begin());
//	ll globalminxfirst = firstcoordsy[0].first;
//	ll globalmaxxfirst = firstcoordsy[0].first;
//	ll globalminxsecond = secondcoordsy[0].first;
//	ll globalmaxxsecond = secondcoordsy[0].first;
//	for (auto it : secondcoordsy) {
//		if (it.first > globalmaxxsecond) globalmaxxsecond = it.first;
//		if (it.first < globalminxsecond) globalminxsecond = it.first;
//	}
//	for (int i = 1; i < cows - 1; i++) {
//		pair <int, int> deletedy = secondcoordsy[0];
//		firstcoordsy.push_back(sortedbyy[i]);
//		secondcoordsy.erase(secondcoordsy.begin());
//		ll firsty = minmaxcalcadd(firstcoordsy, sortedbyy[i], globalmaxxfirst, globalminxfirst, 'y');
//		ll secondy = minmaxcalcsubtract(secondcoordsy, deletedy, globalmaxxsecond, globalminxsecond, 'y');
//		ll newareay = firsty + secondy;
//		if (initial - newareay > optimal && initial - newareay > 0)
//		{
//			optimal = initial - newareay;
//			//cout << newareay;
//		}
//	}
//	
//
//
//	fout << optimal;
//	return 0;
//
//}

//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//bool sorty(pair<ll, ll>& firsty, pair<ll, ll>& secondy) {
//	return(firsty.second < secondy.second);
//}
//
//ll calArea(vector <pair<ll, ll>>& v) {
//	ll minx = 2000000000000, maxx = 0, miny = 20000000000, maxy = 0;
//	for (int i = 0; i < v.size(); i++) {
//		minx = min(minx, v[i].first);
//		maxx = max(maxx, v[i].first);
//		miny = min(miny, v[i].second);
//		maxy = max(maxy, v[i].second);
//	}
//	return (maxx - minx) * (maxy - miny);
//}
//
//vector < pair< ll, ll > > sortedbyy;
//vector < pair< ll, ll > > sortedbyx;
//vector < pair< ll, ll > > original;
//
//int main() {
//	//ifstream fin("C:/Users/cools/8.in");
//	//ifstream fin("split.in");
//	//ofstream fout("split.out");
//	int cows;
//	ll ans = 0;
//	cin >> cows;
//	for (int i = 0; i < cows; i++) {
//		int x, y; cin >> x >> y;
//		original.push_back(make_pair(x, y));
//		sortedbyx.push_back(make_pair(x, y));
//		sortedbyy.push_back(make_pair(x, y));
//	}
//	sort(sortedbyx.begin(), sortedbyx.end());
//	sort(sortedbyy.begin(), sortedbyy.end(), sorty);
//	//ll totalArea1 = calArea(original);
//	//ll totalArea2 = calArea(sortedbyx);
//	//ll totalArea3 = calArea(sortedbyy);
//	//cout << totalArea1 << " " << totalArea2 << " " << totalArea3 << endl;
//	ll totalArea = calArea(original);
//	vector< pair< ll, ll >> newVec1;
//	vector< pair< ll, ll >> newVec2(sortedbyx.begin(), sortedbyx.end());
//	vector< pair< ll, ll >> newVec3;
//	vector< pair< ll, ll >> newVec4(sortedbyy.begin(), sortedbyy.end());
//	for (int i = 0; i < cows; i++) {
//		newVec1.push_back(*(sortedbyx.begin() + i));
//		newVec2.erase(newVec2.begin());
//		ll area1 = calArea(newVec1);
//		ll area2 = calArea(newVec2);
//		newVec3.push_back(*(sortedbyy.begin() + i));
//		newVec4.erase(newVec4.begin());
//		ll area3 = calArea(newVec3);
//		ll area4 = calArea(newVec4);
//		ans = max(ans, (totalArea - min(area1 + area2, area3 + area4)));
//		if (i == cows - 1) {
//			newVec1.clear();
//			newVec2 = sortedbyx;
//			newVec3.clear();
//			newVec4 = sortedbyy;
//		}
//	}
//	cout << ans;
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector < pair< ll, ll > > sortedbyy;
vector < pair< ll, ll > > sortedbyx;
ll sumx[500005], sumy[500005], revsumx[500005], revsumy[500005];
int cows;
bool sorty(pair<ll, ll>& firsty, pair<ll, ll>& secondy){ 
	return(firsty.second < secondy.second);
}
void calArea(vector <pair<ll, ll>>& vx, vector <pair<ll, ll>>& vy) {
	ll minx = 2000000000000, maxx = 0, miny = 20000000000, maxy = 0;
	ll revminx = 2000000000000, revmaxx = 0, revminy = 20000000000, revmaxy = 0;
	for (int i = 0; i < vx.size(); i++) {
		miny = min(miny, vx[i].second);
		maxy = max(maxy, vx[i].second);
		sumx[i] = (vx[i].first - vx[0].first) * (maxy - miny);
	}
	for (int i = 0; i < vy.size(); i++) {
		minx = min(minx, vy[i].first);
		maxx = max(maxx, vy[i].first);
		sumy[i] = (maxx - minx) * (vy[i].second - vy[0].second);
	}
	for (int i = vx.size() - 1; i >= 0; i--) {
		revminy = min(revminy, vx[i].second);
		revmaxy = max(revmaxy, vx[i].second);
		revsumx[i] = (vx[cows - 1].first - vx[i].first) * (revmaxy - revminy);
	}
	for (int i = vy.size() - 1; i >= 0; i--) {
		revminx = min(revminx, vy[i].first);
		revmaxx = max(revmaxx, vy[i].first);
		revsumy[i] = (revmaxx - revminx) * (vy[cows - 1].second - vy[i].second);
	}
}

int main() {
	//ifstream fin("C:/Users/cools/10.in");
	ifstream fin("split.in");
	ofstream fout("split.out");
	ll ans = 0, totalArea;
	fin >> cows;
	for (int i = 0; i < cows; i++) {
		int x, y; fin >> x >> y;
		sortedbyx.push_back(make_pair(x, y));
		sortedbyy.push_back(make_pair(x, y));
	}
	sort(sortedbyx.begin(), sortedbyx.end());
	sort(sortedbyy.begin(), sortedbyy.end(), sorty);
	calArea(sortedbyx, sortedbyy);
	totalArea = sumx[cows - 1];
	for (int i = 0; i < cows - 1; i++) ans = max(ans, (totalArea - min(sumx[i] + revsumx[i + 1], sumy[i] + revsumy[i + 1])));
	fout << ans;
	return 0;
}