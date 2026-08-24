#include <bits/stdc++.h>
using namespace std;
int solve() {
	int n,s; cin >> n >> s;
	int arr[n] = {};
	cin >> arr[0];
	if (arr[0] > s) {
		cout << "No\n";
		return 0;
	} 
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		if (arr[i]-arr[i-1] > s) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}
int main() {
	solve();
	return 0;
}