#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int freq[26] = {};
	string alph = "qwertyuiopasdfghjklzxcvbnm";
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (s[i] == alph[j]) {
				freq[j]++;
				break;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		if (freq[i] == 0) {
			cout << alph[i];
			break;
		}
	}
	return 0;
}