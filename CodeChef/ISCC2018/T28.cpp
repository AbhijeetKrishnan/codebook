#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 9;

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
    int n, q;
    cin >> n >> q;
    unordered_map<long long, int> m;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        long long val = (2LL * a * b) + max(a, b);
        if (m.count(val) == 0) {
            m[val] = 1;
        }
        else {
            m[val]++;
        }
    }
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        long long val = (1ll * k * (k + 1)) / 2;
        int ans;
        if (m.count(val) == 0) {
            ans = -1;
        }
        else {
            ans = mod_inverse(m[val], M);
        }
        cout << ans << "\n";
    }
    return 0;
}