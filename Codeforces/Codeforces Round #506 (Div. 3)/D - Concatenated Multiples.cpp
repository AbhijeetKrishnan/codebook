#include <bits/stdc++.h>

using namespace std;

long long int fast_pow(long long int base, int exp)
{
    long long int res = 1;
    while (exp > 0) {
        if (exp & 1)
            res *= base;
        exp >>= 1;
        base *= base;
    }
    return res;
}

int digits(int n) {
    int res = 0;
    while (n > 0) {
        n /= 10;
        res++;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), digs(n);
    int max_digs = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        digs[i] = digits(a[i]);
        max_digs = max(max_digs, digs[i]);
    }
    vector<map<int, int>> v(max_digs + 1);
    for (int i = 1; i <= max_digs; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = (1LL * (a[j] % k) * (fast_pow(10, i) % k)) % k;
            if (v[i].count(val) == 0) {
                v[i][val] = 1;
            }
            else {
                v[i][val]++;
            }
        }
    }
    long long int ans = 0;
    for (int i = 0; i < n; ++i) {
        int dig = digs[i];
        int alt_val = (k - (a[i] % k)) % k;
        if (v[dig].count(alt_val) == 1) {
            ans += v[dig][alt_val];
            int val = (1LL * (a[i] % k) * (fast_pow(10, dig) % k)) % k;
            if (val == alt_val) {
                ans--;
            }
        }
    }
    cout << ans;
    return 0;
}