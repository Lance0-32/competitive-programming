#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int n,m; cin >> n >> m;
	string s,t; cin >> s >> t;
	int best = 1e9;
	for (int i = 0; i <= n-m; i++) {
		int curr = 0;
		for (int j = 0; j < m; j++) {
			int inc = s[i+j] - t[j];
			if (inc < 0) {
				inc += 10;
			}
			curr += inc;
		}
		best = min(best,curr);
	}
	cout << best << '\n';
	return 0;
}