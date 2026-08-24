#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	long long arr[n] = {};
	long long sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < n; i++) {
		ans += arr[i]*(sum-arr[i]);
	}
	ans = ans >> 1;
	cout << ans;
	return 0;
}