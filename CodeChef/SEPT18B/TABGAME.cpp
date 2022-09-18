#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        string s, t;
        int m, n;
        cin >> s;
        cin >> t;
        m = (int)s.length();
        n = (int)t.length();
        vector<vector<bool>> v(2, vector<bool>(m)), w(2, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            v[0][i] = not ((bool)(s[i] - '0') and ((i == 0) ? (bool)(t[0] - '0') : v[0][i - 1]));
        }
        for (int i = 0; i < m; ++i) {
            v[1][i] = not (v[0][i] and ((i == 0) ? (bool)(t[1] - '0') : v[1][i - 1]));
        }
        for (int i = 0; i < n; ++i) {
            w[0][i] = not ((bool)(t[i] - '0') and ((i == 0) ? (bool)(s[0] - '0') : w[0][i - 1]));
        }
        for (int i = 0; i < n; ++i) {
            w[1][i] = not (w[0][i] and ((i == 0) ? (bool)(s[1] - '0') : w[1][i - 1]));
        }
        /*
        vector<vector<bool>> dp(n, vector<bool>(m));
        for (int i = 0; i < m; ++i) {
            dp[0][i] = not ((bool)(s[i] - '0') and ((i == 0) ? (bool)(t[0] - '0') : dp[0][i - 1]));
        }
        for (int i = 0; i < n; ++i) {
            dp[i][0] = not ((bool)(t[i] - '0') and ((i == 0) ? (bool)(s[0] - '0') : dp[i - 1][0]));
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = not (dp[i - 1][j] and dp[i][j - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        */
        int q;
        cin >> q;
        for (int query = 0; query < q; ++query) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (x < 2) {
                cout << v[x][y];
            }
            else if (y < 2) {
                cout << w[y][x];
            }
            else if (x >= y) {
                x -= y;
                cout << w[1][x+1];
            }
            else {
                y -= x;
                cout << v[1][y+1];
            }
        }
        cout << "\n";
    }
    return 0;
}