#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int fast_pow(int a, int x, int m) {
    int ret_val;
    if (x == 0) {
        ret_val = 1;
    }
    else {
        int tmp = fast_pow(a, x / 2, m);
        ret_val = (1LL * tmp * tmp) % m;
        if (x & 1) {
            ret_val = (1LL * ret_val * a) % m;
        }
    }
    return ret_val;
}

int mod_inverse(int n, int m) {
    return fast_pow(n, m - 2, m);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n, k;
        cin >> n >> k;
        int ans;
        if (k == 1) {
            ans = 1;
        }
        else {
            ans = ((1LL * (fast_pow(k, n + 1, M) - 1) * mod_inverse(k - 1, M)) - 1 + M) % M;
        }
        cout << ans << "\n";
    }
    return 0;
}