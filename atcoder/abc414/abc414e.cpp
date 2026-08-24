#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ll_sqrt(ll n){
	ll l = 0, r = 1e9;
	while (l < r) {
		ll m = (l+r+1) >> 1;
		if (m * m <= n) {
			l = m;
		} else {
			r = m-1;
		}
	}
	return l;
}
int main() {
	ll n; cin >> n;
	ll mod = 998244353;
	ll m = ll_sqrt(n);
	//consider every pair a > b; there exists n*(n+1)/2 ways to pick a>=b
	//we immediately get rid of the a=b case in the loop
	ll ans = n % mod;
	ans = ((ans * (ans+1)) >> 1) % mod;
	for (ll i = 1; i <= n; i++) {
		//diff_small counts the number of times a factor appears across all n numbers
		ll diff_small = n/i;
		if (diff_small <= m) {
			break;
		} else {
			ans = (ans - diff_small) % mod;
		}
	}
	for (ll i = 1; i * i <= n; i++) {
		//diff_large counts the number of "large numbers" that appear exactly i times as a factor
		//so floor(n/(i+1)) + 1 to floor(n/i)
		ll diff_large = 0;
		diff_large = n/i;
		diff_large -= n/(i+1);
		diff_large = (diff_large * i) % mod;
		ans = (ans - diff_large) % mod;
	}
	ans = (ans + mod) % mod;
	cout << ans << '\n';
	return 0;
}