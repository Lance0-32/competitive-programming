#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x; cin >> n >> x;
	if (x == 1) {
		if (n >= 1600 and n <= 2999) {
			cout <<"Yes\n";
		} else {
			cout << "No\n";
		}
	} else {
		if (n >= 1200 and n <= 2399) {
			cout <<"Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}