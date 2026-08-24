#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int n, m; cin >> n >> m;
    map<int,int> mp;
    int ans = 0;
    vector<vector<int>> vec;
    for (int i = 0; i < n; i++) {
        int a,d,b; cin >> a >> d >> b;
        vector<int> tmp;
        tmp = {d,b,a};
        vec.push_back(tmp);
        //cout << a << " ";
        mp[a]++;
        if(mp[a] == 1) {
            ans++;
        }
    }
    sort(vec.begin(),vec.end());
    int i = 0;
    for (int j = 1; j <= m; j++) {
        for (; i < n && vec[i][0] == j; i++) {
            //cout << vec[i][0] << " " << vec[i][1] << " " << vec[i][2] << "\n";
            mp[vec[i][1]]++;
            if (mp[vec[i][1]] == 1) {
                ans++;
            }
            mp[vec[i][2]]--;
            if (mp[vec[i][2]] == 0) {
                ans--;
            }
        }
        cout << ans << "\n";
    }
	return 0;
}