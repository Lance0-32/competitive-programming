#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	int ans = 0;
	bool log = false;
	while (t--) {
		string i; cin >> i;
		if (i == "login") {
			log = true;
		} else if (i == "logout") {
			log = false;
		} else if (i == "private" and log == false) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}