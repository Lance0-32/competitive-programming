#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        vec[i] = {x,i+1};
    }
    sort(vec.begin(),vec.end());
    cout << vec[0][1] << " " << vec[1][1] << " " << vec[2][1] << " ";
	return 0;
}