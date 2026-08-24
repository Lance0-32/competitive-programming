#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int x,y; cin >> x >> y;
	x *= (1<< y);
	cout << x;
	return 0;
}