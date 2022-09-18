#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const int M = 1e9 + 7;

lli fast_pow(lli a, lli n, int M) {
    lli ret_val;
    if (n == 0) {
        ret_val = 1;
    }
    else {
        ret_val = fast_pow(a, n / 2, M);
        ret_val = (ret_val * ret_val) % M;
        if (n & 1) {
            ret_val = (ret_val * a) % M;
        }
    }
    return ret_val;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        lli n, k;
        cin >> n >> k;
        lli ans = fast_pow(k - 1, n - 1, M);
        ans = (ans * k) % M;
        cout << ans << '\n';
    }
    return 0;
}