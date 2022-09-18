#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, m;
        cin >> n >> m;
        int p[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> p[i][j];
                p[i][j]--;
            }
        }
        int q;
        cin >> q;
        int ans[m];
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            for (int i = 0; i < m; ++i) {
                ans[i] = p[l][i];
            }
            for (int i = l + 1; i <= r; ++i) {
                for (int j = 0; j < m; ++j) {
                    ans[j] = p[i][ans[j]];
                }
            }
            long long int ret = 0;
            for (int i = 0; i < m; ++i) {
                ret += (long long int)((i + 1) * (ans[i] + 1));
            }
            cout << ret << "\n";
        }
    }
    return 0;
}