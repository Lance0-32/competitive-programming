#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	int l,r; cin >> l >> r;
	int ans = 0;
	while (t--) {
		int x,y; cin >> x >> y;
		if (x <= l and y >= r) {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}