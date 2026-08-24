#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int arr[n] = {};
	for (int i = 0; i < n; i++) cin >> arr[i];
	int k; cin >> k;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (k <= arr[i]) {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}