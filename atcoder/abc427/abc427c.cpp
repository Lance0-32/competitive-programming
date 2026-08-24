#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

int main() {
	int n,m; cin >> n >> m;
	int mask = 1 << n;
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; i++) {
		int u,v; cin >> u >> v;
		u--; v--;
		graph[u].push_back(v); // no need for second edge to avoid overcount (u->v, v->u)
	}
	int ans = 1e9;
	for (int i = 0; i < mask; i++) {
		int curr = 0;
		for (int j = 0; j < n; j++) {
			int side_j = (i & (1 << j)) > 0;
			for (int k = 0; k < graph[j].size(); k++) {
				int side_k = (i & (1 << graph[j][k])) > 0;
				if (side_j == side_k) {
					curr++;
				}
			}
		}
		//cout << curr << " ";
		ans = min(ans,curr);
	}
	cout << ans;
	return 0;
}