#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
const int M = 1'000'000'000 + 7;
vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

int f(int n, int k) {
    //cout << n << " " << k << "\n";
    if (n < k) return 0;
    else if (n == k) return 2;
    else if (k == 1) return 2;
    else if (dp[n][k] != -1) {
        return dp[n][k];
    }
    else {
        dp[n][k] = f(n - 1, k - 1);
        for (int i = k - 1; i < n - 1; ++i) {
            dp[n][k] = ((long long int)dp[n][k] + 2 * f(i, k - 1)) % M;
        }
        return dp[n][k];
    }
}

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        for (int i = k; i <= n; ++i) {
            long long int res = f(i, k);
            ans = (int)(ans + res) % M;
            //cout << res << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}