#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        long long int sum = 0;
        for (int i = 1; i <= r; i += 2) {
            int x = l, y = r;
            int x_mod = l % i;
            if (x_mod != 0)
              x += (i - x_mod);
            y -= y % i;
            int count = (y - x) / i + 1;
            //cout << i << ' ' << count << '\n';
            sum += 1LL * count * i;
        }
        cout << sum << '\n';
    }
    return 0;
}