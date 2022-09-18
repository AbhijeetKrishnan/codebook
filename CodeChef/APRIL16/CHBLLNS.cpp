#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int r, g, b;
        cin >> r >> g >> b;
        long long int k;
        cin >> k;
        long long int ans = min(k - 1, r) + min(k - 1, b) + min(k - 1, g) + 1;
        cout << ans << '\n';
    }
    return 0;
}