#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int h,b; cin >> h >> b;
	int x = max(0,h-b);
	cout << x;
	return 0;
}