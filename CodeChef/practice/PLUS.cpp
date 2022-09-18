#include <iostream>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        int up[n][m], down[n][m], left[n][m], right[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        int ans = a[1][1] + a[1][0] + a[1][2] + a[0][1] + a[2][1];
        
        for (int j = 0; j < m; ++j) {
            up[1][j] = a[0][j];
        }
        for (int i = 2; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                up[i][j] = max(up[i-1][j] + a[i-1][j], a[i-1][j]);
            }
        }

        for (int j = 0; j < m; j++) {
            down[n-2][j] = a[n-1][j];
        }
        for (int i = n - 3; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                down[i][j] = max(down[i+1][j] + a[i+1][j], a[i+1][j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            left[i][1] = a[i][0];
        }
        for (int j = 2; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                left[i][j] = max(left[i][j-1] + a[i][j-1], a[i][j-1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            right[i][m-2] = a[i][m-1];
        }
        for (int j = m - 3; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                right[i][j] = max(right[i][j+1] + a[i][j+1], a[i][j+1]);
            }
        }
        for (int i = 1; i + 1 < n; ++i) {
            for (int j = 1; j + 1 < m; ++j) {
                //cout << i << ' ' << j << ' ' << a[i][j] << " (" << up[i][j] << ", " << down[i][j] << ", " << left[i][j] << ", " << right[i][j] << ")\n";
                ans = max(ans, a[i][j] + up[i][j] + down[i][j] + left[i][j] + right[i][j]);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}