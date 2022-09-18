#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = l; i <= r; ++i) {
            int rem = i % 10;
            if (rem == 2 || rem == 3 || rem == 9) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}