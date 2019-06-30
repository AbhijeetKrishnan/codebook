#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        int L, v, l, r;
        cin >> L >> v >> l >> r;
        int ans = L/v - r/v + (l - 1)/v;
        cout << ans << "\n";
    }
    return 0;
}