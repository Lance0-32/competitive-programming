#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll verify(ll a, ll x) {
	vector<ll> vec;
	ll y = x;
	while (x > 0) {
		vec.push_back(x % a);
		x = x / a;
	}
	int k = vec.size();
	for (int i = 0; i <= k; i++) {
		if (i == k) {
			return y;
		} else if (vec[i] != vec[k-i-1]) {
			return 0;
		}
	}
}
int main() {
	ll a,n; cin >> a >> n;
	vector<ll> vec;
	ll ans = 0;
	for (ll i = 1; i < 1000000; i++) {
		ll small = 0, big = 0;
		ll x = i;
		vector<ll> vec;
		while (x > 0) {
			vec.push_back(x % 10ll);
			x = x / 10ll;
		}
		int k = vec.size();
		for (int i = k-1; i >= 0; i--) {
			small = 10ll*small+vec[i];
			big = 10ll*big+vec[i];
		}
		big = 10ll*big+vec[0];
		for (int i = 1; i < k; i++) {
			small = 10ll*small+vec[i];
			big = 10ll*big+vec[i];
		}
		if (small <= n) {
			ans += verify(a,small);
			if (big <= n) {
				ans += verify(a,big);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}