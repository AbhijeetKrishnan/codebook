#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

long long fast_pow(long long base, long long exponent, long long modulus) {
    if (modulus == 1) return 0;
    base = base % modulus;
    long long res = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            res = (res * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return res;
}

long long anbn(long long a, long long b, long long n, long long div) {
    return (fast_pow(a, n, div) + fast_pow(b, n, div)) % div;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        long long a, b, n;
        cin >> a >> b >> n;
        long long g = 1;
        for (int i = 1; 1LL * i * i <= a - b; i++) {
            if ((a - b) % i == 0) {
                long long div1 = i;
                long long div2 = (a - b) / i;
                if (anbn(a, b, n, div1) == 0) {
                    g = max(g, div1);
                }
                if (anbn(a, b, n, div2) == 0) {
                    g = max(g, div2);
                }
            }
        }
        if (a == b) {
            g = anbn(a, b, n, M);
        }
        cout << (g % M) << "\n";
    }
    return 0;
}