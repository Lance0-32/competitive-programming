#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,q; cin >> n >> q;
	int freq[n+1] = {};
	for (int i = 0; i < q; i++) {
		int x; cin >> x;
		if (x > 0) {
			cout << x << " ";
			freq[x]++;
		} else {
			int low = 1e9;
			int idx = 0;
			for (int i = 1; i <= n; i++) {
				if (low > freq[i]) {
					low = freq[i];
					idx = i;
				}
			}
			cout << idx << " ";
			freq[idx]++;
		}
	}
	return 0;
}