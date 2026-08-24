#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int n; cin >> n;
	ll a[n] = {}, b[n] = {}, c[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	ll dp[n][3] = {};
	dp[0][0] = a[0];
	dp[n-2][0] = dp[n-1][0] = dp[n-1][1] = dp[0][1] = dp[0][2] = dp[1][2] =  -1e18;
	for (int i = 1; i < n-2; i++) {
		dp[i][0] = dp[i-1][0] + a[i];
	}
	for (int i = 1; i < n-1; i++) {
		dp[i][1] = max(dp[i-1][1],dp[i-1][0]) + b[i];
	}
	for (int i = 2; i < n; i++) {
		dp[i][2] = max(dp[i-1][1],dp[i-1][2]) + c[i];
	}
	// for (int i = 0; i < 3; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << dp[j][i] << " ";
	// 	}
	// 	cout << '\n';
	// }
	cout << dp[n-1][2];
	return 0;
}