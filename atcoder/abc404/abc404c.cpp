#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	if (n == m) {
		int freq[n] = {};
		vector<vector<int>> graph(n);
		for (int i = 0; i < n; i++) {
			int a,b; cin >> a >> b;
			a--; b--;
			freq[a]++; freq[b]++;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		bool vis[n] = {};
		for (int i = 0; i <= n; i++) {
			if (i == n) {
				//verify that there are not multiple cycles
				queue<int> bfs;
				bfs.push(0);
				while (!bfs.empty()) {
					int x = bfs.front();
					bfs.pop();
					vis[x] = true;
					for (int j = 0; j < graph[x].size(); j++) {
						if (!vis[graph[x][j]]) {
							bfs.push(graph[x][j]);
						}
					}
				}
				for (int j = 0; j <= n; j++) {
					if (j == n) {
						cout << "Yes\n";
					}
					if (!vis[j]) {
						cout << "No\n";
						break;
					}
				}
			} else if (freq[i] != 2) {
				cout << "No\n";
				break;
			}
		}
	} else {
		cout << "No\n";
	}
	return 0;
}