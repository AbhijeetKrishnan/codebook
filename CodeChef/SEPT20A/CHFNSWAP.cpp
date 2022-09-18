#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;
        lli total = (lli)n * (n + 1) / 2;
        if (total & 1) {
            cout << "0\n";
            continue;
        }
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            lli a = (lli)mid * (mid + 1) / 2;
            if (a <= total / 2) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        int k = lo - 1;
        lli ans;
        if ((lli)k * (k + 1) / 2 == total / 2) {
            ans = (lli)k * (k - 1) / 2 + (lli)(n - k) * (n - k - 1) / 2 + (n - k);
        }
        else {
            ans = n - k;
        }
        cout << ans << '\n';
    }
    return 0;
}