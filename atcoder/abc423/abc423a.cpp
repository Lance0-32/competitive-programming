#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int x,c; cin >> x >> c;
	x /= 1000+c;
	x *= 1000;
	cout << x;
	return 0;
}