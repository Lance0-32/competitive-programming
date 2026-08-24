#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	int arr[n] = {}, freq[m] = {};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		freq[arr[i]-1]++;
	}
	int ans = 0;
	bool flag = true;
	while (flag) {
		for (int i = 0; i < m; i++) {
			if (freq[i] == 0) {
				cout << ans << '\n';
				flag = false;
				break;
			}
		}
		n--;
		freq[arr[n]-1]--;
		ans++;
	}
	return 0;
}