#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,q; cin >> n >> q;
	int arr[n] = {};
	for (int i = 0; i < n; i++) {
		arr[i] = i+1;
	}
	int offset = 0;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int p,x; cin >> p >> x;
			p--;
			int k = (p+offset) % n;
			arr[k] = x;
		} else if (t == 2) {
			int p; cin >> p;
			p--;
			int k = (p+offset) % n;
			cout << arr[k] << '\n';
		} else {
			int k; cin >> k;
			offset = (offset + k) % n;
		}
	}
	return 0;
}