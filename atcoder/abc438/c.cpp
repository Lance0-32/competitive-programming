#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int n; cin >> n;
	int ptr = 0;
	int arr[n] = {};
	int par[n] = {}, chd[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		par[i] = i-1;
		chd[i] = i+1;
	}
	int ans = n;
	while (true) {
		int w,x,y,z;
		w = ptr;
		x = chd[w];
		if (x != n) {
			y = chd[x];
		} else {
			break;
		}
		if (y != n) {
			z = chd[y];
		} else {
			break;
		}
		//cout << w << " " << x << " " << y << " " << z << " " << '\n';
		if (z > 0 and z < n) {
			if (arr[w] == arr[x] and arr[x] == arr[y] and arr[y] == arr[z]) {
				int ctr = 0;
				if (chd[z] != n) {
					par[chd[z]] = par[w];
				}
				if (par[w] != -1) {
					chd[par[w]] = chd[z];
				}
				ptr = chd[z];
				while (ctr < 4) {
					ctr++;
					if (par[ptr] != -1) {
						ptr = par[ptr];
					} else {
						break;
					}
				}
				ans -= 4;
			} else {
				ptr = x;
			}
		} else {
			break;
		}
		if (ptr == n or ans < 4) {
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}