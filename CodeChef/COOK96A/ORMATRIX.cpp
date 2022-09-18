#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (auto &e: v) {
            cin >> e;
        }
        vector<vector<int>> ans(n, vector<int>(m));
        vector<bool> rows(n, false);
        vector<bool> cols(m, false);
        bool is_possible = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == '1') {
                    rows[i] = true;
                    cols[j] = true;
                    is_possible = true;
                }
            }
        }
        if (is_possible) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (v[i][j] == '1') {
                        ans[i][j] = 0;
                    }
                    else if (rows[i] or cols[j]) {
                        ans[i][j] = 1;
                    }
                    else {
                        ans[i][j] = 2;
                    }
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << "-1 ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}