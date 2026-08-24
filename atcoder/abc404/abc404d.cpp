#include <bits/stdc++.h>
using namespace std;

int main() {
	long long high = 1e18;
	int n,m; cin >> n >> m;
	vector<long long> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	vector<vector<int>> a(n);
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int x; cin >> x;
			a[x-1].push_back(i);
		}
	}
	for (int i = 2; i < pow(3,n); i++) { //because you need to visit at least 2 zoos
		int k = i;
		int freq[m] = {};
		long long cost = 0;
		for (int j = 0; j < n; j++) {
			int x = k % 3;
			if (x > 0) {
				for (int p = 0; p < a[j].size(); p++) {
					freq[a[j][p]] += x;
				}
				cost += (long long)x * c[j];
			}
			k = k / 3;
		}
		bool flag = true;
		for (int i = 0; i < m; i++) {
			if (freq[i] < 2) {
				flag = false;
				break;
			}
		}
		if (flag) {
			high = min(high, cost);
		}
	}
	cout << high;
	return 0;
}