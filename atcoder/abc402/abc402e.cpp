#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x; cin >> n >> x;
	long double prob[8][3] = {};
	for (int i = 0; i < n; i++) {
		cin >> prob[i][0] >> prob[i][1] >> prob[i][2];
	}
	//to make imple more convienient (fake problems that are literally unsolvable)
	for (int i = n; i < 8; i++) {
		prob[i][0] = 0;
		prob[i][1] = 10000;
		prob[i][2] = 0;
	}
	long double dp[x+1][256] = {};
	for (int i = 0; i < 256; i++) {
		//not the cleanest imple...
		if (i >= 128) {
			dp[0][i] += prob[0][0];
		}
		if (i % 128 >= 64) {
			dp[0][i] += prob[1][0];
		}
		if (i % 64 >= 32) {
			dp[0][i] += prob[2][0];
		}
		if (i % 32 >= 16) {
			dp[0][i] += prob[3][0];
		}
		if (i % 16 >= 8) {
			dp[0][i] += prob[4][0];
		}
		if (i % 8 >= 4) {
			dp[0][i] += prob[5][0];
		}
		if (i % 4 >= 2) {
			dp[0][i] += prob[6][0];
		}
		if (i % 2) {
			dp[0][i] += prob[7][0];
		}
	}
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < 256; j++) {
			dp[i][j] = dp[i-1][j];
			if (j < 128) {
				dp[i][j] = max(dp[i][j], (dp[i-int(prob[0][1])][j]*(1-(prob[0][2]/100)) + dp[i-int(prob[0][1])][j+128]*(prob[0][2]/100)));

			}
			if (j % 128 < 64) {
				dp[i][j] = max(dp[i][j], (dp[i-int(prob[1][1])][j]*(1-(prob[1][2]/100)) + dp[i-int(prob[1][1])][j+64]*(prob[1][2]/100)));
			}
			if (j % 64 < 32) {
				dp[i][j] = max(dp[i][j], (dp[i-int(prob[2][1])][j]*(1-(prob[2][2]/100)) + dp[i-int(prob[2][1])][j+32]*(prob[2][2]/100)));
			}
			if (j % 32 < 16) {
				dp[i][j] = max(dp[i][j], (dp[i-int(prob[3][1])][j]*(1-(prob[3][2]/100)) + dp[i-int(prob[3][1])][j+16]*(prob[3][2]/100)));
			}
			if (j % 16 < 8) {
				dp[i][j] = max(dp[i][j], (dp[i-int(prob[4][1])][j]*(1-(prob[4][2]/100)) + dp[i-int(prob[4][1])][j+8]*(prob[4][2]/100)));
			}
			if (j % 8 < 4) {
				dp[i][j] = max(dp[i][j], (dp[i-int(prob[5][1])][j]*(1-(prob[5][2]/100)) + dp[i-int(prob[5][1])][j+4]*(prob[5][2]/100)));
			}
			if (j % 4 < 2) {
				dp[i][j] = max(dp[i][j], (dp[i-int(prob[6][1])][j]*(1-(prob[6][2]/100)) + dp[i-int(prob[6][1])][j+2]*(prob[6][2]/100)));
			}
			if (j % 2 == 0) {
				dp[i][j] = max(dp[i][j], (dp[i-int(prob[7][1])][j]*(1-(prob[7][2]/100)) + dp[i-int(prob[7][1])][j+1]*(prob[7][2]/100)));
			}
		}
	}
	cout << fixed << setprecision(12) << dp[x][0];
	return 0;
}