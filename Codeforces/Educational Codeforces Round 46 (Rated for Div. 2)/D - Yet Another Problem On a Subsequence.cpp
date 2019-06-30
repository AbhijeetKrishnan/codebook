#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
const int M = 998244353;

int ncr[N + 1][N + 1];

int main() {
    for (int n = 0; n <= N; ++n) {
        for (int r = 0; r <= N; ++r) {
            if (n < r) {
                ncr[n][r] = 0;
            }
            else if (r == 0) {
                ncr[n][r] = 1;
            }
            else {
                ncr[n][r] = (ncr[n-1][r] + ncr[n-1][r-1]) % M;
            }
        }
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int dp[n+1];
    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = 0;
        if (a[i] > 0) {
            for (int j = i + a[i] + 1; j <= n; ++j) {
                dp[i] = (1LL * ncr[j - i - 1][a[i]] * dp[j] + dp[i]) % M;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + dp[i]) % M;
    }
    cout << ans;
    return 0;
}