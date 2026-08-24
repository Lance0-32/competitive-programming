#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	string s; cin >> s;
	int ctr = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'E') {
			ctr++;
		} else {
			ctr--;
		}
	}
	if (ctr > 0) {
		cout << "East";
	} else {
		cout << "West";
	}
	return 0;
}