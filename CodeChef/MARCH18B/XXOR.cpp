#include <bits/stdc++.h>

#define BITS 31

using namespace std;

int main()
{
	int n, q;
	cin >> n >> q;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ones[n+1][BITS];
	for (int i = 0; i < BITS; ++i) {
		ones[0][i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < BITS; ++j) {
			ones[i][j] = ones[i-1][j] + ((a[i-1] >> j) & 1);
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		int tmp[BITS];
		for (int i = 0; i < BITS; ++i) {
			tmp[i] = ones[r][i] - ones[l-1][i];
		}
		/*
		for (int i = BITS - 1; i >= 0; --i) {
			cout << tmp[i] << ' ';
		}
		cout << '\n';
		*/
		int c = r - l + 1;
		int ans = 0;
		for (int i = 0; i < BITS; ++i) {
			if (2 * tmp[i] < c) {
				ans |= (1 << i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}