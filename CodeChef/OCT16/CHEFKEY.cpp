/**
 * Author: rashomon
 * Platform: Codechef
 * URL: https://www.codechef.com/OCT16/problems/CHEFKEY
 * Problem Name: Chef and Keyboard
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        uint64_t n, m, c;
        cin >> n >> m >> c;
        int ans = 0;
        for (uint64_t i = 1, j = c; i <= c; ++i, j = c / i) {
            if (i * j == c && i <= n && j <= m) {
                ++ans;
                //cout << i << ' ' << j << '\n';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}