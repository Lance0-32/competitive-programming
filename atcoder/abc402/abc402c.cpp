#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	vector<vector<int>> vec(m);
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		int high = 0;
		for (int j = 0; j < k; j++) {
			int x; cin >> x;
			vec[i].push_back(x);
		}
	}
	vector<vector<int>> mapping(n);
	vector<int> last(m);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mapping[i].push_back(x);
		mapping[i].push_back(i+1);
	}
	sort(mapping.begin(),mapping.end());
	for (int i = 0; i < m; i++) {
		int high = 0;
		for (int j = 0; j < vec[i].size(); j++) {
			int k = mapping[vec[i][j]-1][1];
			high = max(high,k);
		}
		last[i] = high;
	}
	sort(last.begin(), last.end());
	last.push_back(1e9);
	int curr = 0;
	for (int i = 1; i <= n; i++) {
		while (last[curr] <= i) {
			curr++;
		}
		cout << curr << '\n';
	}
	return 0;
}