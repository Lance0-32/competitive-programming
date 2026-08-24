#include <bits/stdc++.h>
using namespace std;

int main() {
	int h,w; cin >> h >> w;
	string arr[h] = {};
	queue<tuple<int,int,char>> bfs;
	bool vis[h][w] = {};
	for (int i = 0; i < h; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 'E') {
				vis[i][j] = true;
				if (i > 0) {
					if (arr[i-1][j] == '.') {
						bfs.push(make_tuple(i-1, j, 'v'));
					}
				}
				if (j > 0) {
					if (arr[i][j-1] == '.') {
						bfs.push(make_tuple(i, j-1, '>'));
					}
				}
				if (i < h-1) {
					if (arr[i+1][j] == '.') {
						bfs.push(make_tuple(i+1, j, '^'));
					}
				}
				if (j < w-1) {
					if (arr[i][j+1] == '.') {
						bfs.push(make_tuple(i, j+1, '<'));
					}
				}
			}
		}
	}
	while (!bfs.empty()) {
		tuple<int, int, char> vals = bfs.front();
		bfs.pop();
		if (vis[get<0>(vals)][get<1>(vals)] == false) {
			int i = get<0>(vals), j = get<1>(vals);
			vis[i][j] = true;
			arr[i][j] = get<2>(vals);
			if (i > 0) {
				if (arr[i-1][j] == '.') {
					bfs.push(make_tuple(i-1, j, 'v'));
				}
			}
			if (j > 0) {
				if (arr[i][j-1] == '.') {
					bfs.push(make_tuple(i, j-1, '>'));
				}
			}
			if (i < h-1) {
				if (arr[i+1][j] == '.') {
					bfs.push(make_tuple(i+1, j, '^'));
				}
			}
			if (j < w-1) {
				if (arr[i][j+1] == '.') {
					bfs.push(make_tuple(i, j+1, '<'));
				}
			}
		}
	}
	for (int i = 0; i < h; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}