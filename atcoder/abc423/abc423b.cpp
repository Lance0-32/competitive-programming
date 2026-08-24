#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int n; cin >> n;
	int first = -1, last = -1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == 1) {
			if (first == -1) {
				first = i;
			}
			last = i;
		}
	}
	cout << last-first;
	return 0;
}