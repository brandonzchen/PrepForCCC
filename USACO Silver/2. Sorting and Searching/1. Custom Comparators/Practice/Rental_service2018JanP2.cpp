
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()

bool decending(const ll & a, const ll & b) {
	return a > b;
}
bool decendingpair(const pair<ll, ll>& a, const pair<ll, ll>& b) {
	return a.first > b.first;
}

int main()
{
	//freopen("2018JanP2test.txt", "r", stdin);
	//ifstream cin("rental.in");
	//ofstream cout("rental.out");
	ll cows, shops, rentals;
	cin >> cows >> shops >> rentals;
	vector<pair<ll, ll>> shopprice;
	vector<ll> rentalprefix;
	vector<ll> cowmilk(cows, 0);
	vector<ll> originalcow;
	for (int i = 0; i < cows; i++) {
		ll temp; cin >> temp;
		cowmilk.push_back(temp);
		originalcow.push_back(temp);
	}
	sort(all(originalcow), decending);
	sort(all(cowmilk), decending);
	for (int i = 0; i < cows; i++) {
		if (i > 0) {
			cowmilk[i] += cowmilk[i - 1];
		}
	}
	ll maxgallons = 0;
	for (int i = 0; i < shops; i++) {
		ll max, price;
		cin >> max >> price;
		maxgallons += max;
		pair<ll, ll>temp;
		temp = make_pair(price, max);
		shopprice.push_back(temp);
	}
	for (int i = 0; i < rentals; i++) {
		ll rentalprice;
		cin >> rentalprice;
		rentalprefix.push_back(rentalprice);
	}
	sort(all(rentalprefix), decending);
	for (int i = 0; i < rentals; i++) {
		if (i > 0) {
			rentalprefix[i] += rentalprefix[i - 1];
		}
	}
	sort(all(shopprice), decendingpair);
	vector <ll> gallons;
	if (maxgallons >= cowmilk[cows - 1]) {
		for (int i = 0; i < shops; i++) {
			vector<ll> temp(shopprice[i].second, shopprice[i].first);
			gallons.insert(gallons.end(), temp.begin(), temp.end());
		}
	}
	if (maxgallons < cowmilk[cows - 1]) {
		for (int i = 0; i < shops; i++) {
			vector<ll> temp(shopprice[i].second, shopprice[i].first);
			gallons.insert(gallons.end(), temp.begin(), temp.end());
		}
		vector<ll>temp(cowmilk[cows - 1] - maxgallons, 0);
		gallons.insert(gallons.end(), temp.begin(), temp.end());
	}
	for (int i = 0; i < gallons.size(); i++) {
		if (i > 0) {
			gallons[i] += gallons[i - 1];
		}
	}

	
	
	

	//for (int i = 0; i < cowmilk.size(); i++) {
	//	for (int j = 0; j < shops; j++) {
	//		if (shopprice[j].second > originalcow[i]) {
	//			cowmilk[i] += originalcow[i] * shopprice[j].first;
	//			shopprice[j].second -= originalcow[i];
	//			originalcow[i] = 0;
	//		}
	//		if (shopprice[j].second < originalcow[i]) {
	//			cowmilk[i] += shopprice[j].second * shopprice[j].first;
	//			originalcow[i] -= shopprice[j].second;
	//			shopprice[j].second = 0;
	//				
	//		}
	//		if (shopprice[j].second == 0) {
	//			continue;
	//		}
	//		if (originalcow[i] == 0) {
	//			break;
	//		}
	//		
	//	}
	//	if (i > 0) {
	//		cowmilk[i] += cowmilk[i - 1];
	//	}
	//}




	
	ll maximum = 0;
	
	for (int i = 0; i <= cows; i++) {
		ll shopped = i;
		ll rented = cows - i;
		ll currentrent = 0;
		ll currentshop = 0;
		if (rented >= rentalprefix.size()) {
			currentrent = rentalprefix[rentals - 1];
		}
		if (rented < rentalprefix.size() && rented > 0) {
			currentrent = rentalprefix[cows - shopped - 1];
		}
		if (shopped > 0) {
			currentshop = gallons[cowmilk[i-1] - 1];
		}
		ll current = currentshop + currentrent;
		maximum = max(maximum, current);

	}
	cout << maximum;

}