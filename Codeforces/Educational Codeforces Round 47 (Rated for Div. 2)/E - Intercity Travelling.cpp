#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;

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

int coeff(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return (1LL * (n + 2) * fast_pow(2, n - 1, M)) % M;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = n - 1; i >= 0; i--) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + 1LL * coeff(i) * a[i]) % M;
    }
    printf("%d", ans);
    return 0;
}