#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	pair<string,ll> arr[n] = {};
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		ll x; cin >> x;
		arr[i] = make_pair(s,x);
		if (sum + arr[i].second > 100ll) {
			sum = 1e18;
			cout << "Too Long\n";
			break;
		} else {
			sum += arr[i].second;
		}
	}
	if (sum != 1e18){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < arr[i].second; j++) {
				cout << arr[i].first;
			}
		}
		cout << '\n';
	}
	return 0;
}