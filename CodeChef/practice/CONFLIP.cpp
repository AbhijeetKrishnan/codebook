#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int g;
        cin >> g;
        while (g--) {
            int i, n, q;
            cin >> i >> n >> q;
            int ans;
            if (i == q) {
                ans = n / 2;
            }
            else {
                if (n & 1) {
                    ans = n / 2 + 1;
                }
                else {
                    ans = n / 2;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}