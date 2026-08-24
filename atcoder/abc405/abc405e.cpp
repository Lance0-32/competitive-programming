#include <bits/stdc++.h>
using namespace std;
long long fast_expo(long long x, long long y, long long mod) {
	long long ans = 1;
	long long mult = x;
	while (y > 0) {
		if (y & 1) {
			ans = (ans * mult) % mod;
		}
		mult = (mult * mult) % mod;
		y = y >> 1;
	}
	return ans;
}
long long inv_fac(long long x) {
	long long mod = 998244353;
	return (fast_expo(x,mod-2,mod));
}
long long fac[3000010] = {};
void build_fac() {
	long long mod = 998244353;
	fac[0] = 1;
	for (int i = 1; i < 3e6+10; i++) {
		fac[i] = (fac[i-1] * i) % mod;
	}
}
long long choose(long long n, long long k) {
	long long mod = 998244353;
	long long num = fac[n];
	long long div1 = fac[k];
	long long div2 = fac[n-k];
	long long denom = (div1 * div2) % mod;
	long long ans = (num*(inv_fac(denom))) % mod;
	return ans;
}
int main() {
	build_fac();
	long long a,o,b,g; cin >> a >> o >> b >> g;
	long long ans = 0;
	long long mod = 998244353;
	if (g == 0) {
		ans = choose(a+b+o, o);
	} else {
		for (int i = 0; i <= b; i++) {
			long long curr = (choose(b+g-i-1, g-1) * choose(a+o+i,o)) % mod;
			ans = (ans + curr) % mod;
		}
	}
	cout << ans << '\n';
	return 0;
}