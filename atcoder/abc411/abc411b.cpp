#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int arr[n-1] = {};
	for (int i = 0; i < n-1; i++) cin >> arr[i];
	for (int i = 0; i < n-1; i++) {
		int ans = 0;
		for (int j = i; j < n-1; j++) {
			ans += arr[j];
			cout << ans << " ";
		}
		cout << '\n';
	}
	return 0;
}