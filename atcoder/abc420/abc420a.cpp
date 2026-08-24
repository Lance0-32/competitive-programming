#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int x,y; cin >> x >> y;
	x = (x+y-1)%12+1;
	cout << x;
	return 0;
}