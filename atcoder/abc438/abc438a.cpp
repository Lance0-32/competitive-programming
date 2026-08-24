#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

int main() {
	int d, t; cin >> d >> t;
	int x = (t-d+1000) % 7 + 1;
	cout << x << '\n';
	return 0;
}