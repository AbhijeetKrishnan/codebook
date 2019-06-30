#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s;
    cin >> t;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i + m - 1 < n; ++i) {
        bool is_substring = true;
        for (int j = i; j - i + 1 <= m and is_substring; ++j) {
            if (s[j] != t[j - i]) {
                is_substring = false;
            }
        }
        if (is_substring) {
            dp[i][i + m - 1]++;
        }
    }
    for (int j = 1; j < n; ++j) {
        for (int i = j; i > 0; i--) {
            dp[i - 1][j] += dp[i][j];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j + 1 < n; j++) {
            dp[i][j + 1] += dp[i][j];
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for (int query = 0; query < q; ++query) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << dp[l][r] << "\n";
    }
    return 0;
}