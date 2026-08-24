#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	int diff[n+1] = {};
	for (int i = 0; i < m; i++) {
		int x,y; cin >> x >> y;
		diff[x-1]++; diff[y]--;
	}
	int low = 1e6, curr = 0;
	for (int i = 0; i < n; i++) {
		curr += diff[i];
		low = min(curr, low);
	}
	cout << low << '\n';
	return 0;
}