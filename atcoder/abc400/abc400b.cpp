#include <bits/stdc++.h>
using namespace std;
 
int main() {
	long long n,m; cin >> n >> m;
	long long ans = 1;
	long long curr = n;
	for (int i = 1; i <= m+1; i++) {
		if (i == m+1) {
			cout << ans << '\n';
		} else {
			ans += curr;
			if (ans > 1e9) {
				cout <<"inf\n";
				break;
			} else {
				curr *= n;
			}
		}
	}
	return 0;
}