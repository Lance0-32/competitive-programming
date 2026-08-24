#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int valid(ll n) {
    int streak = 0;
    int ans = 0;
    while (n > 0) {
        int zero = (n % 10 == 0);
        n /= 10;
        streak = streak * zero + zero;
        ans = max(ans, (int)(streak >= 2)); 
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        for (ll i = 1; i <= 100; i++) {
            if (valid(n*i)) {
                cout << n*i << '\n';
                break;
            }
        }
    }
    return 0;
}