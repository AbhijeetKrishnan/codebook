#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int LIM = 1e5;
vector<int> factorial(LIM + 1);

int fast_pow(int a, int x, int m) {
    int res = 1;
    while (x > 0) {
        if (x & 1) {
            res = ((long long int)res * a) % m;
        }
        a = ((long long int)a * a) % m;
        x >>= 1;
    }
    return res;
}

int mod_inv(int a, int m) {
    return fast_pow(a, m - 2, m);
}

int ncr(int n, int r, int m) {
    int numerator = factorial[n];
    int denominator = ((long long int)factorial[r] * factorial[n - r]) % m;
    return ((long long int)numerator * mod_inv(denominator, m)) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    factorial[0] = 1;
    for (int i = 1; i <= LIM; i++) {
        factorial[i] = ((long long int)factorial[i - 1] * i) % MOD;
    }
    int num_tests;
    cin >> num_tests;
    for (int test = 0; test < num_tests; test++) {
        int n;
        cin >> n;
        string A, B;
        cin >> A;
        cin >> B;
        int x = 0, y = 0;
        for (char c : A) {
            if (c == '0') x++;
        }
        for (char c : B) {
            if (c == '0') y++;
        }
        int ans = 0;
        int a = min(x, y);
        int b = min(n - x, n - y);
        while (0 <= a and a <= min(x, y) and 0 <= b and b <= min(n - x, n - y)) {
            int k = a + b;
            ans = (ans + ncr(n, k, MOD)) % MOD;
            a--, b--;
        }
        cout << ans << "\n";
    }
    return 0;
}