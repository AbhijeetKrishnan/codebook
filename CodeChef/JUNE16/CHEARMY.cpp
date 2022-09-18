#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		uint64_t k, b5 = 0, pow = 1;
		cin >> k;
		--k;
		while (k != 0) {
			b5 += pow * (k % 5);
			k /= 5;
			pow *= 10;
		}
		cout << (b5 << 1) << '\n';
	}
	return 0;
}