#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int curr;
        cin >> curr;
        int min = curr;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            cin >> curr;
            if (curr < min) {
                min = curr;
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}