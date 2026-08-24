#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q; cin >> n >> q;
	int arr[n] = {};
	int ans = 0;
	while (q--) {
		int x; cin >> x;
		x--;
		arr[x] = 1-arr[x];
		int temp = 1;
		if (x > 0) {
			if (arr[x-1] == 1) {
				temp--;
			}
		}
		if (x < n-1) {
			if (arr[x+1] == 1) {
				temp--;
			}
		}
		if (arr[x] == 0) {
			temp = -1*temp;
		}
		ans += temp;
		cout << ans << '\n';
	}
	return 0;
}