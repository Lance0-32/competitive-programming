#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k; cin >> n >> k;
	vector<long long> pref;
	long long mod = 1e9;
	for (int i = 0; i <= k; i++) {
		pref.push_back(i);
	}
	for (int i = k; i <= n; i++){
		pref.push_back((pref[i]+pref[i]-pref[i-k] + mod) % mod);
	}
	long long ans = pref[n+1]-pref[n];
	if (ans < 0) {
		ans += mod;
	}
	cout << ans;
	return 0;
}