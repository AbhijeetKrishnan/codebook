#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int ans = 0;
        int n;
        int res, sum;
        cin >> n;
        // get sum
        cout << 1 << " " << (1 << 20) << endl;
        cin >> sum;
        sum -= (1 << 20) * n; // 10^6 * 10^3 = 10^9
        ans |= sum & 1;
        //cout << sum << '\n';
        for (int k = 1; k < 20; k++) {
            // cout << k << " " << (1 << k) << '\n';
            cout << 1 << " " << (1 << k) << endl;
            cin >> res;
            if (res == -1) {
                exit(0);
            }
            else {
                int diff = (res - sum) / (1 << k);
                int even = (diff + n) / 2;
                int odd = n - even;
                int parity = odd & 1;
                ans |= parity << k;
                //cout << "k = " << k << " parity = " << parity << '\n';
                // ans |= res & (1 << ((n - ((((res - sum) >> k) + n) >> 1)) & 1));
            }
        }
        cout << 2 << " " << ans << endl;
        cin >> res;
        if (res == -1) {
            exit(0);
        }
    }
    return 0;
}