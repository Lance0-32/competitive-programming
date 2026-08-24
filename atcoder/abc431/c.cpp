#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int n,m,k; cin >> n >> m >> k;
	int cnt = 0;
	vector<int> head(n), body(m);
	for (int i = 0; i < n; i++) {
		cin >> head[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> body[i];
	}
	sort(head.begin(),head.end());
	sort(body.begin(),body.end());
	int c1 = 0, c2 = 0;
	while (c1 < n and c2 < m) {
		if (head[c1] <= body[c2]) {
			c1++; c2++; cnt++;
		} else {
			c2++;
		}
	}
	if (cnt >= k) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}