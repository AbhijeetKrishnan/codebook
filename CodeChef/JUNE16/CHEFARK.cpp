#include <bits/stdc++.h>

using namespace std;

const int LIM = 100000;
const int M = 1e9 + 7;

vector<int> fact(LIM + 1);

int fast_pow(int a, int x, int m) {
	if (x == 0) {
		return 1;
	}
	int res = fast_pow(a, x >> 1, m);
	res = (1LL * res * res) % m;
	if (x & 1) {
		res = (1LL * res * a) % m;
	}
	return res;
}

int mod_inverse (int a, int m) {
	return fast_pow(a, m - 2, m);
}

int ncr(int n, int r, int m) {
	int numerator = fact[n];
	int denominator = (1LL * fact[r] * fact[n - r]) % m;
	int res = (1LL * numerator * mod_inverse(denominator, m)) % m;
	return res;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		fact[0] = 1;
		for (int i = 1; i <= LIM; ++i) {
			fact[i] = (1LL * i * fact[i - 1]) % M;
		}
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (auto &e : v) {
			cin >> e;
		}
		bool has_0 = false;
		for (auto &e : v) {
			if (e == 0) {
				has_0 = true;
				--n;
			}
		}
		int ans = 0;
		if (has_0) {
			if (k > n) k = n;
			for (int i = 0; i <= k; ++i) {
				ans = (ans + ncr(n, i, M)) % M;
			}
		}
		else {
			if (k > n && (k - n) % 2 == 0) {
				k = n;
			}
			else if (k > n && (k - n) % 2 != 0) {
				k = n - 1;
			}
			if (k & 1) {
				for (int i = 1; i <= k; i += 2) {
					ans = (ans + ncr(n, i, M)) % M;
				}
			}
			else {
				for (int i = 0; i <= k; i += 2) {
					ans = (ans + ncr(n, i, M)) % M;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}