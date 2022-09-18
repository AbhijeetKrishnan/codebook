#include <bits/stdc++.h>
 
using namespace std;
 
const int M = 1'000'000'000 + 7;
 
__int128 fast_pow(__int128 base, __int128 exponent, __int128 modulus) {
    if (modulus == 1) return 0;
    base = base % modulus;
    __int128 res = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            res = (res * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return res;
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
        long long ans;
        if (a == b) {
            ans = (fast_pow(a, n, M) + fast_pow(b, n, M)) % M;
        }
        else {
            ans = (__gcd((fast_pow(a, n, a - b) + fast_pow(b, n, a - b)) % (a - b), (__int128)(a - b))) % M;
        }
        cout << ans << "\n";
    }
    return 0;
}