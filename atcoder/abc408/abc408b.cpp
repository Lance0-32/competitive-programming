#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> orig(n), fin;
	for (int i = 0; i < n; i++) {
		cin >> orig[i];
	}
	sort(orig.begin(), orig.end());
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (curr != orig[i]) {
			curr = orig[i];
			fin.push_back(curr);
		}
	}
	cout << fin.size() << '\n';
	for (int i = 0; i < fin.size(); i++) {
		cout << fin[i] << " ";
	}
	return 0;
}