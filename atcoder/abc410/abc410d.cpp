#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	int ans = 1000000;
	bool vis[n][2048] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2048; j++) {
			vis[i][j] = false;
		}
	}
	vector<vector<pair<int,int>>> graph(n);
	for (int i = 0; i < m; i++) {
		int a,b,h; cin >> a >> b >> h;
		a--; b--;
		graph[a].push_back(make_pair(b,h));
	}
	queue<pair<int,int>> bfs;
	bfs.push(make_pair(0,0));
	vis[0][0] = true;
	while(!bfs.empty()) {
		int x = bfs.front().first, w = bfs.front().second;
		bfs.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int l = graph[x][i].first, k = w ^ graph[x][i].second;
			if (vis[l][k] == false) {
				vis[l][k] = true;
				bfs.push(make_pair(l,k));
			}
		}
	}
	for (int i = 0; i < 2048; i++) {
		if (vis[n-1][i] == true) {
			ans = i;
			break;
		}
	}
	if (ans == 1000000) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
	return 0;
}