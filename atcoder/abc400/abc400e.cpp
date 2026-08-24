#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 1010;
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    	}
	}
	vector<int> prime;
	for (int i = 0; i < 1010; i++) {
		if (is_prime[i] == true) {
			prime.push_back(i);
		}
	}
	int t; cin >> t;
	while (t--) {
		long long x; cin >> x;
		long long n = sqrt(x);
		for (long long i = n; i >= 5; i--) {
			int count = 0;
			long long k = i;
			long long m = k;
			for (long long j = 0; (prime[j] * prime[j] < m) or (j == prime.size()); j++) {
				if (m % prime[j] == 0) {
					count++;
					while (m % prime[j] == 0) {
						m /= prime[j];
					}
				}
			}
			if (m != 1) {
				count++;
			}
			if (count == 2) {
				n = k * k;
				break;
			}
		}
		cout << n << '\n';
	}
	return 0;
}