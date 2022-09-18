#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        vector<int> sc(n), tm(n);
        vector<vector<int>> dp(n + 1, vector<int>(w + 1));
        for (int i = 0; i < n; ++i) {
            int c, p;
            cin >> c >> p >> tm[i];
            sc[i] = c * p;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= w; ++j) {
                //cout << i << " " << j << "\n";
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else if (j < tm[i-1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - tm[i - 1]] + sc[i - 1]);
                }
            }
        }
        cout << dp[n][w] << '\n';
    }
    return 0;
}