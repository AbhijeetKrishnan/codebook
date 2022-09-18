#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int fast_pow(int base, int exponent) {
    int res = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            res *= base;
        }
        exponent >>= 1;
        base *= base;
    }
    return res;
}

int lt_prime[N + 1];
int T;
int n;
vector<int> factor[N + 1];
int cnt[N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 2; i <= N; ++i) {
        if (lt_prime[i] == 0) {
            lt_prime[i] = i;
            for (int j = i + i; j <= N; j += i) {
                if (lt_prime[j] == 0)
                    lt_prime[j] = i;
            }
        }
    }
    cin >> T;
    for (int test = 0; test < T; test++) {
        cin >> n;
        for (int i = 0; i <= N; ++i) {
            factor[i].clear();
        }
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            while (val > 1) {
                int factor_val = 0;
                int prime = lt_prime[val];
                while ((val % prime) == 0) {
                    factor_val++;
                    val /= prime;
                }
                factor[prime].push_back(factor_val);
                cnt[prime] += factor_val;
            }
        }
        int ans = 1;
        for (int p = 2; p <= N; ++p) {
            if (cnt[p] < n) {
                continue;
            }
            int l = 0, r = 20;
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                int need = 0;
                for (int k: factor[p]) {
                    if (k >= mid) {
                        need -= (k - mid) >> 1;
                    }
                    else {
                        need += mid - k;
                    }
                }
                need += (n - (int)factor[p].size()) * mid;
                if (need <= 0) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            ans *= fast_pow(p, l);
        }
        cout << ans << "\n";
    }
    return 0;
}