#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,q; cin >> n >> q;
	ll a[n] = {}, b[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += min(a[i],b[i]);
	}
	while (q--) {
		char c; ll x,v; cin >> c >> x >> v;
		x--;
		if (c == 'A') {
			sum += min(v,b[x])-min(a[x],b[x]);
			a[x] = v;
		} else {
			sum += min(a[x],v)-min(a[x],b[x]);
			b[x] = v;
		}
		cout << sum << '\n';
	}
	return 0;
}