#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    for (int i = 0; i < k; ++i) {
        int t1, f1, t2, f2;
        cin >> t1 >> f1 >> t2 >> f2;
        int ans = 0;
        if (t1 != t2) {
            if (f1 < a) {
                ans += a - f1;
                ans += abs(t2 - t1);
                ans += abs(a - f2);
            }
            else if (f1 > b) {
                ans += f1 - b;
                ans += abs(t2 - t1);
                ans += abs(b - f2);
            }
            else {
                ans += abs(t2 - t1);
                ans += abs(f1 - f2);
            }
        }
        else {
            ans += abs(f1 - f2);
        }
        cout << ans << "\n";
    }
    return 0;
}