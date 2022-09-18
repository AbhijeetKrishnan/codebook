#include <bits/stdc++.h>

using namespace std;
const int M = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, s;
		cin >> n >> m >> s;
		vector<int> v(m);
		for (auto &e : v) {
			cin >> e;
		}
		vector<vector<int>> dp(m + 1, vector<int>(n, 0));
		dp[0][s - 1] = 1;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dp[i][j] != 0) {
					if (j - v[i] >= 0) {
						dp[i + 1][j - v[i]] = (dp[i + 1][j - v[i]] + dp[i][j]) % M;
					}
					if (j + v[i] < n) {
						dp[i + 1][j + v[i]] = (dp[i + 1][j + v[i]] + dp[i][j]) % M;
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			cout << dp[m][i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}