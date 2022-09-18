#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MOD2 = MOD - 1;

int T;
int n, k;

int fast_pow(int a, int x, int m) {
    if (x == 0) {
        return 1;
    }
    else if (x % 2 == 0) {
        int tmp = fast_pow(a, x / 2, m);
        return (1LL * tmp * tmp) % m;
    }
    else {
        int tmp = fast_pow(a, x / 2, m);
        return (((1LL * tmp * tmp) % m) * a) % m;
    }
}

int main() {
    cin >> T;
    for (int test = 0; test < T; ++test) {
        cin >> n >> k;
        vector<vector<int>> nCr(n, vector<int>(k, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i < j) {
                    nCr[i][j] = 0;
                }
                else if (i == j || j == 0) {
                    nCr[i][j] = 1;
                }
                else {
                    nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD2;
                }
            }
        }
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 1;
        int tmp = nCr[n-1][k-1];
        for (int i = 0; i < n; ++i) {
            int gt = n - 1 - i;
            int lt = i;
            int times;
            times = (tmp - nCr[gt][k-1]- nCr[lt][k-1]) % MOD2;
            if (times < 0) {
                times += MOD2;
            }
            ans = (1LL * ans * fast_pow(a[i], times, MOD)) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}