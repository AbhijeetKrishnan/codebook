#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<int> row(n);
    int row_xor = 0;
    for (int i = 0; i < n; ++i) {
        cin >> row[i];
        ans[i][0] = row[i];
        row_xor ^= row[i];
    }
    int col_xor = 0;
    vector<int> col(m);
    for (int i = 0; i < m; ++i) {
        cin >> col[i];
        if (i != 0) ans[0][i] = col[i];
        col_xor ^= col[i];
    }
    if (row_xor != col_xor) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        ans[0][0] = row[0] ^ col_xor ^ col[0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}