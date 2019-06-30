#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    int ans = 0;
    for (int i = 1; i * i <= y; ++i) {
        if (y % i == 0) {
            int div1 = i;
            int div2 = y / i;
            if (__gcd(div1, div2) == x and l <= div1 and div1 <= r and l <= div2 and div2 <= r) {
                ans += 2;
                if (div1 == div2) ans--;
            }
        }
    }
    cout << ans;
    return 0;
}