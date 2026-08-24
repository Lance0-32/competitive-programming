#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,m; cin >> n >> k >> m;
    priority_queue<pair<ll,ll>> pq;
    queue<ll> rq;
    for (int i = 0; i < n; i++) {
        ll x,y; cin >> x >> y;
        pq.emplace(y, x);
    }
    set<int> uniq;
    ll ans = 0;
    while (uniq.size() < m) {
        int val = pq.top().first;
        int color = pq.top().second;
        int sz = uniq.size();
        uniq.insert(color);
        if (sz == uniq.size()) {
            rq.push(val);
        } else {
            ans += val;
        }
        pq.pop();
    }
    while(m < k) {
        int high = 0;
        int type = -1;
        if (!pq.empty()) {
            high = pq.top().first;
            type = 0;
        }
        if (!rq.empty()) {
            if (rq.front() > high) {
                high = rq.front();
                type = 1;
            }
        }
        if (type == 0) {
            pq.pop();
        } else {
            rq.pop();
        }
        ans += high;
        m++;
    }
    cout << ans << '\n';
}