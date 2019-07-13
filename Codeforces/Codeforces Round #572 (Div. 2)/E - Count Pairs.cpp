#include <iostream>
#include <unordered_map>

using namespace std;

int modular_pow(int base, int exponent, int modulus) {
    if (modulus == 1) {
        return 0;
    }
    // assert (modulus - 1) * (modulus - 1) does not overflow base
    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = ((long long int)result * base) % modulus;
        }
        exponent >>= 1;
        base = ((long long int)base * base) % modulus;
    }
    return result;
}

int get_value(int a, int p, int k) {
    int res = modular_pow(a, 4, p);
    res = (res - (((long long int)a * k)) % p + p) % p;
    return res;
}

int main() {
    int n, p, k;
    cin >> n >> p >> k;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int val = get_value(a, p, k);
        if (m.find(val) != m.end()) {
            m[val]++;
        }
        else {
            m[val] = 1;
        }
    }
    long long int ans = 0;
    for (auto e: m) {
        ans += (long long int)e.second * (e.second - 1) / 2;
    }
    cout << ans;
    return 0;
}