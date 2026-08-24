#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,m; cin >> n >> m;
	string arr[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int score[n] = {};
	for (int i = 0; i < m; i++) {
		int zero = 0, one = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] == '0') {
				zero++;
			} else {
				one++;
			}
		}
		for (int j = 0; j < n; j++) {
			if ((arr[j][i] == '1' and zero > one) or (arr[j][i] == '0' and one > zero)) {
				score[j]++;
			}
		}
	}
	int high = 0;
	for (int i = 0; i < n; i++) {
		high = max(high, score[i]);
	}
	for (int i = 0; i < n; i++) {
		if (score[i] == high) {
			cout << i+1 << " ";
		}
	}
	return 0;
}