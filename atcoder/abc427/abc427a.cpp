#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	string s; cin >> s;
	int n = s.length() >> 1;
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	for (int i = n+1; i < n+n+1; i++) {
		cout << s[i];
	}
	return 0;
}