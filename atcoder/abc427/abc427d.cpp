#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

int main() {
	int t; cin >> t;
	while (t--) {
		int n,m,k; cin >> n >> m >> k;
		string s; cin >> s;
		vector<vector<int>> graph(n);
		for (int i = 0; i < m; i++) {
			int u,v; cin >> u >> v;
			u--; v--;
			graph[v].push_back(u);
		}
		string s_turn = s;
		for (int i = k-1; i >= 0; i--) {
			//Bob's turn
			for (int j = 0; j < n; j++) {
				s_turn[j] = 'A';
			}
			for (int j = 0; j < n; j++) {
				if (s[j] == 'B') {
					for (int k = 0; k < graph[j].size(); k++) {
						s_turn[graph[j][k]] = 'B';
					}
				}
			}
			s = s_turn;
			//Alice's turn
			for (int j = 0; j < n; j++) {
				s_turn[j] = 'B';
			}
			for (int j = 0; j < n; j++) {
				if (s[j] == 'A') {
					for (int k = 0; k < graph[j].size(); k++) {
						s_turn[graph[j][k]] = 'A';
					}
				}
			}
			s = s_turn;
		}
		//cout << s << " ";
		if (s[0] == 'A') {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	}
	return 0;
}