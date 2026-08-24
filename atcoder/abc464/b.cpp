#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
	int h, w; cin >> h >> w;
    string emp;
    emp = "";
    for (int i = 0; i < w; i++) {
        emp += ".";
    }
    vector<string> vec;
    bool flag = false;
    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        if (s != emp or flag == true) {
            flag = true;
            vec.push_back(s);
        }
    }
    while (flag == true) {
        string s = vec[vec.size()-1];
        if (s == emp) {
            vec.pop_back();
        } else {
            flag = false;
        }
    }
    int l = 0, r = 1;
    string emp2;
    emp2 = "";
    for (int i = 0; i < vec.size(); i++) {
        emp2 += ".";
    }
    for (int i = 0; i < w; i++) {
        string s;
        s = "";
        for (int j = 0; j < vec.size(); j++) {
            s += vec[j][i];
        }
        if (s == emp2) {
            if (l == i) {
                l = i+1;
            }
            if (r == i + 1) {
                r = i;
            }
        } else {
            r = i;
        }
    }
    for (int i = 0; i < vec.size(); i++) {
        for (int j = l; j <= r; j++) {
            cout << vec[i][j];
        }
        cout << '\n';
    }
	return 0;
}