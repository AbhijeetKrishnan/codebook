#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

const int MOD = 1e9 + 7;
const int LIMIT = 1e5;

lli fast_pow(lli base, int exp, int mod) {
    lli res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

lli mod_inv(lli a, int mod) {
    return fast_pow(a, mod - 2, mod);
}

lli nCr(lli n, lli r, int mod, vector<lli> &factorial) {
    lli num = factorial[n];
    lli den = (factorial[r] * factorial[n - r]) % mod;
    return (num * mod_inv(den, mod)) % mod;
}

int main() {
    vector<lli> factorial(LIMIT + 1);
    factorial[0] = 1;
    for (int i = 1; i <= LIMIT; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &ele: v) {
            cin >> ele;
        }
        int max = v[0], cnt = 1;
        for (int i = 1; i < n; i++) {
            if (v[i] > max) {
                max = v[i];
                cnt = 1;
            }
            else if (v[i] == max) {
                cnt++;
            }
        }
        lli ans;
        if (cnt % 2 == 0) {
            lli draws = (nCr(cnt, cnt / 2, MOD, factorial) * fast_pow(2, n - cnt, MOD)) % MOD;
            ans = (fast_pow(2, n, MOD) - draws + MOD) % MOD;
        }
        else {
            ans = fast_pow(2, n, MOD);
        }
        cout << ans << "\n";
    }
    return 0;
}