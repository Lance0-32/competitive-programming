#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int n; cin >> n;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		int j = ans;
		while (j > 0) {
			ans += j % 10;
			j /= 10;
		}
	}
	cout << ans << '\n';
	return 0;
}