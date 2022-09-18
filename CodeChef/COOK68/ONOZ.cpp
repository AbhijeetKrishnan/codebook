#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, m;
        cin >> h >> m;
        int ans = 1;
        for (int i = 1; i < 10; ++i) {
            int hh = i;
            while (hh < h) {
                int mm = i;
                while (mm < m) {
                    ++ans;
                    mm = mm * 10 + i;
                }
                hh = hh * 10 + i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}