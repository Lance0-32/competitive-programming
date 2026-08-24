#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k; cin >> n >> k;
	int temp = 0;
	string s; cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			if (i != 0) {
				s[i-1] = '.';
			}
			if (i != n-1) {
				s[i+1] = '.';
			}
			temp++;
		}
	}
	int low_temp = temp;
	int streak = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			streak++;
		} else {
			temp += (streak + 1) >> 1;
			streak = 0;
		}
	}
	temp += (streak + 1) >> 1;
	streak = 0;
	if (temp == k) {
		int last = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '?') {
				streak++;
			} else {
				if (streak % 2) {
					bool is_o = true;
					for (int j = last; j < i; j++) {
						if (is_o) {
							s[j] = 'o';
							is_o = false;
						} else {
							s[j] = '.';
							is_o = true;
						}
					}
				}
				streak = 0;
				last = i+1;
			}
		}
		if (streak % 2) {
			bool is_o = true;
			for (int j = last; j < n; j++) {
				if (is_o) {
					s[j] = 'o';
					is_o = false;
				} else {
					s[j] = '.';
					is_o = true;
				}
			}
		}
	} else if (low_temp == k) {
		for (int i = 0; i < n; i++) {
			if (s[i] == '?') {
				s[i] = '.';
			}
		}
	}
	cout << s;
	return 0;
}