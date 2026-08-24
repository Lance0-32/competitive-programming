#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n; cin >> n;
	long long k = n >> 1; n = n >> 2;
	long long ans = sqrtl(k);
	long long x = sqrtl(n);
	ans += x;
	cout << ans << '\n';
	return 0;
}