#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int fast_pow(int a, int x, int m) {
    if (x == 0) {
        return 1;
    }
    else {
        int tmp = fast_pow(a, x / 2, m);
        if (x & 1) {
            return (((1LL * tmp * tmp) % m) * a) % m;
        }
        else {
            return (1LL * tmp * tmp) % m;
        }
    }
}

int mod_inv(int n, int m) {
    return fast_pow(n, m - 2, m);
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int tmp = n;
    int factors = 0;
    while (not (tmp & 1)) {
        tmp >>= 1;
        factors++;
    }
    int p = (fast_pow(2, n - 1 - factors, M) - tmp) % M;
    if (p < 0) {
        p += M;
    }
    int q = fast_pow(2, n - 1 - factors, M);
    int ans = (1LL * p * mod_inv(q, M)) % M;
    cout << ans;
    return 0;
}