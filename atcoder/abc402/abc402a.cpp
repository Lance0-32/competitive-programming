#include <iostream>
using namespace std;
 
int main() {
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < 'a') {
			cout << s[i];
		}
	}
	return 0;
}