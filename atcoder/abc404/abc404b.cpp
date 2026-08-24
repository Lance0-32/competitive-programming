#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	char s[n][n][4] = {}, t[n][n] = {};
	for (int i = 0; i < n; i++) {
		string w; cin >> w;
		for (int j = 0; j < n; j++) {
			s[i][j][0] = w[j];
			//90 deg: goes to [j][n-1-i]
			s[j][n-1-i][1] = s[i][j][0];
			//180 deg: both indexes flip
			s[n-1-i][n-1-j][2] = s[i][j][0];
			//270 deg: grid flips 90 then 180
			//this means [j][n-1-i]->[n-1-j][i]
			s[n-1-j][i][3] = s[i][j][0];
		}
	}
	for (int i = 0; i < n; i++) {
		string w; cin >> w;
		for (int j = 0; j < n; j++) {
			t[i][j] = w[j];
		}
	}
	int ans[4] = {0,1,2,3};
	for (int x = 0; x < 4; x++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s[i][j][x] != t[i][j]) {
					ans[x]++;
				}
			}
		}
	}
	int fin = min({ans[0],ans[1],ans[2],ans[3]});
	cout << fin;
	return 0;
}