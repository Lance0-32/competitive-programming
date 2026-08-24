#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n] = {}, b[n] = {};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (b[a[i]] != i) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}