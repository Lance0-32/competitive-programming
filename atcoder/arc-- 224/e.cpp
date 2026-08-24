#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        stack<char> st;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == 'A') {
                if (!st.empty()) {
                    if (st.top() == 'B') {
                        st.pop();
                        if (!st.empty()) {
                            if (st.top() == 'C') {
                                st.pop();
                                
                            }
                        }
                    }
                }
            } else {
                st.push(s[i]);
            }
        }
        cout << st.size() << '\n';
    }
    return 0;
}