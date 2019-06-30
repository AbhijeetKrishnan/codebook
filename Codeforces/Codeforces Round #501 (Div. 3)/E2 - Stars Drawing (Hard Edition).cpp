#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &e: v) {
        cin >> e;
    }
    vector<int> x, y, s;
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < m; ++j) {
            int cnt;
            for (cnt = 0; cnt < min({i + 1, j + 1, n - i, m - j}); cnt++) {
                if (v[i][j+cnt] != '*' or v[i][j-cnt] != '*' or v[i+cnt][j] != '*' or v[i-cnt][j] != '*') {
                    break;
                }
            }
            if (cnt > 1) {
                for (int k = 0; k < cnt; ++k) {
                    seen[i][j + k] = true;
                    seen[i][j - k] = true;
                    seen[i + k][j] = true;
                    seen[i - k][j] = true;
                }
                x.push_back(i + 1);
                y.push_back(j + 1);
                s.push_back(cnt - 1);
            }
        }
    }
    bool all_seen = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '*') {
                all_seen = all_seen and seen[i][j];
            }
        }
    }
    if (all_seen) {
        cout << x.size() << "\n";
        for (int i = 0; i < x.size(); ++i) {
            cout << x[i] << " " << y[i] << " " << s[i] << "\n";
        }
    }
    else {
        cout << "-1";
    }
    return 0;
}