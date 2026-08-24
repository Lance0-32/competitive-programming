#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	queue<int> q;
	while (t--) {
		int x; cin >> x;
		if (x == 1) {
			int y; cin >> y;
			q.push(y);
		} else {
			int y = q.front();
			q.pop();
			cout << y << '\n';
		}
	}
	return 0;
}