#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int c[n] = {}, a[n] = {};
	for (int i = 0; i < n-1; i++) {
		cin >> c[i+1];
	}
	for (int i = 0; i < n-1; i++) {
		cin >> a[i+1];
	}
	int ans = 0;
	for (int i = n-1; i > 0; i--) {
		if (a[i] > 0) {
			bool flag = true;
			//step 1: ensure no "free moves" (jump to existing bean)
			for (int j = i-1; j >= i-c[i]; j--) {
				if (a[j] > 0) {
					a[j] += a[i];
					a[i] = 0;
					ans++;
					flag = false;
					break;
				}
			}
			//step 2: if no free moves, a two move sequence should bring you as left as possible
			//if we need to break ties, move as left as possible in first move
			//note that this always works (proof is by greedy, any move 1 that doesnt accomplish this strictly limits your options)
			if (flag) {
				int best_index = i;
				int bnj = i;
				for (int j = i-1; j >= i-c[i]; j--) {
					if (bnj >= j-c[j]) {
						best_index = j;
						bnj = j-c[j];
					}
				}
				a[best_index] += a[i];
				a[i] = 0;
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}