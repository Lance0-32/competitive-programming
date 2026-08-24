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
long long mod_inv(long long x, long long mod) {
	return fast_expo(x, mod-2, mod);
}
int main() {
	int n; cin >> n;
	int cnt[n] = {};
	for (int i = 0; i < n; i++) {
		cnt[i] = 6;
	}
	long long mult = 1, ans = 0, mod = 998244353;
	long long fast_inv[7] = {};
	fast_inv[1] = 1;
	for (int i = 2; i <= 6; i++) {
		fast_inv[i] = mod_inv(i, mod);
	}
	vector<pair<long long,long long>> faces;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			int x; cin >> x;
			faces.push_back(make_pair(x,i));
		}
	}
	sort(faces.begin(),faces.end(),greater<pair<long long, long long>>());
	for (int i = 0; i < 6*n; i++) {
		long long val = faces[i].first, idx = faces[i].second;
		ans = (ans + (val*fast_inv[cnt[idx]]) % mod * mult) % mod;
		mult = (mult * fast_inv[cnt[idx]] * (cnt[idx]-1)) % mod;
		cnt[idx]--;
		if (mult == 0) {
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}