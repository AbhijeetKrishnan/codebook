#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int tmp = 0;
            int z = (i < n) ? 0 : i - n + 1;
            for (int j = z; j <= i - z; ++j) {
                tmp += a[j][n - 1 - (i - j)];
            }
            ans = max(ans, tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}