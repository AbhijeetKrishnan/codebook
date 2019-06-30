#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int n, m;
ull a[20][20];
ull k;
unordered_map<ull, ull> dp[20][20];

/*
ull f(int p, int q, ull k) {
    ull ret;
    if (p < 0 || q < 0) {
        ret = 0;
    }
    else if (dp[p][q].count(k) == 1) {
        ret = dp[p][q][k];
    }
    else {
        ret = dp[p][q][k] = f(p - 1, q, k ^ a[p][q]) + f(p, q - 1, k ^ a[p][q]);
    }
    return ret;
}
*/

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    dp[0][0][a[0][0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (auto e : dp[i - 1][0]) {
            dp[i][0][a[i][0] ^ e.first] = e.second;
        }
    }
    for (int j = 1; j < m; ++j) {
        for (auto e : dp[0][j - 1]) {
            dp[0][j][a[0][j] ^ e.first] = e.second;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            for (auto e : dp[i][j - 1]) {
                dp[i][j][a[i][j] ^ e.first] = e.second;
            }
            for (auto e : dp[i - 1][j]) {
                if (dp[i][j].count(a[i][j] ^ e.first) == 0) {
                    dp[i][j][a[i][j] ^ e.first] = e.second;
                }
                else {
                    dp[i][j][a[i][j] ^ e.first] += e.second;
                }
            }
        }
    }
    ull ans = dp[n - 1][m - 1][k];
    cout << ans;
    return 0;
}