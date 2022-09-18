#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int maxn = 1 << N;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> cnt(maxn, 0), a(n), dp(maxn);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++cnt[a[i]];
		}
		for (int i = 0; i < maxn; ++i) {
			dp[i] = cnt[i];
		}
		for (int i = 0; i < N; ++i) {
			for (int mask = 0; mask < maxn; ++mask) {
				if (mask & (1<<i)) {
					dp[mask] += dp[mask ^ (1<<i)];
				}
			}
		}
		long long int ans = 0;
		for (int i = 0; i < maxn; ++i) {
			ans += ((long long int)cnt[i]) * (dp[i] - cnt[i]) + (long long int)cnt[i] * (cnt[i] - 1) / 2;
		}
		cout << ans << '\n';
	}
	return 0;
}