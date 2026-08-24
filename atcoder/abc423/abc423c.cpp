#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int n,r; cin >> n >> r;
	int arr[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bool flag = false;
	int ans = 0;
	for (int i = 0; i < r; i++) {
		if (arr[i] == 1) {
			if (flag == true) {
				ans += 2;
			} 
		} else {
			flag = true;
			ans += 1;
		}
	}
	flag = false;
	for (int i = n-1; i >= r; i--) {
		if (arr[i] == 1) {
			if (flag == true) {
				ans += 2;
			} 
		} else {
			flag = true;
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}