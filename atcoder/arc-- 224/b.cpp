#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        // build square
        ll s = sqrt(n) + 2;
        while (s*s > n) {
            s--;
        }
        // s*s square = 2s row/col with val 2s(s-1)
        ll ans = 2*s*(s-1);
        n -= s*s;
        // build rect side, allow s for s * (s+1)
        if (n > 0) {
            int w = min(n, s);
            ans += 2*w-1;
            n -= w;
        }
        // build second rect side
        if (n > 0) {
            ans += 2*n-1;
        }
        cout << ans << '\n';
    }
    return 0;
}