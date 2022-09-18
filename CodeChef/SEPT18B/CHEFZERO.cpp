#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    int each = (n * m) / k;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
    int ctr = 0, curr_sec = 1;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; ++j) {
                v[i][j] = curr_sec;
                ctr++;
                if (ctr == each) {
                    curr_sec = min(k, curr_sec + 1);
                    ctr = 0;
                }
            }
        }
        else {
            for (int j = m - 1; j >= 0; --j) {
                v[i][j] = curr_sec;
                ctr++;
                if (ctr == each) {
                    curr_sec = min(k, curr_sec + 1);
                    ctr = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}