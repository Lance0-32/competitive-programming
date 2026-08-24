#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,m; cin >> n >> m;
	vector<ll> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(),vec.end());
	priority_queue<ll> pq;
	for (int i = 1; i < n; i++) {
		pq.push(vec[i]-vec[i-1]);
	}
	ll ans = vec[n-1]-vec[0];
	for (int i = 0; i < m-1; i++) {
		ans -= pq.top();
		pq.pop();
	}
	cout << ans << '\n';
	return 0;
}