#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int x; cin >> x;
	int n; cin >> n;
	int arr[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bool attached[n] = {};
	int q; cin >> q;
	while (q--) {
		int y; cin >> y; y--;
		if (attached[y]) {
			x -= arr[y];
			attached[y] = 0;
		} else {
			x += arr[y];
			attached[y] = 1;
		}
		cout << x << '\n';
	}
	return 0;
}