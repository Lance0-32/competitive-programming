#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

int main() {
	int n; cin >> n;
	int weights[n] = {};
	int sum_weight = 0;
	ll all_bot = 0;
	ll happ_diff[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
		sum_weight += weights[i];
		ll h,b; cin >> h >> b;
		happ_diff[i] = h-b;
		all_bot += b;
	}
	int max_hw = sum_weight/2;
	ll dp[n+1][max_hw+1] = {};
	for (int j = 0; j <= max_hw; j++) {
		dp[0][j] = -1e18;
	}
	dp[0][0] = all_bot;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= max_hw; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= weights[i-1]) {
				dp[i][j] = max(dp[i-1][j-weights[i-1]]+happ_diff[i-1], dp[i][j]);
			}
		}
	}
	ll ans = 0;
	for (int j = 0; j <= max_hw; j++) {
		ans = max(ans, dp[n][j]);
	}
	cout << ans << '\n';
	return 0;
}