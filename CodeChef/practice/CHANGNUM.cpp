#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int N = 1e5;

int fast_pow(int base, int exponent, int modulus) {
    if (modulus == 1) {
        return 0;
    }
    int res = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            res = (1LL * res * base) % modulus;
        }
        exponent >>= 1;
        base = (1LL * base * base) % modulus;
    }
    return res;
}

int mod_inverse(int a, int m) {
    return fast_pow(a, m - 2, m);
}

vector<int> parent(N + 1);
vector<int> _size(N + 1);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (_size[a] < _size[b])
            swap(a, b);
        parent[b] = a;
        _size[a] += _size[b];
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> fact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = (1LL * i * fact[i-1]) % M;
    }
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (auto &e: a) {
            cin >> e;
        }
        for (auto &e: b) {
            cin >> e;
        }
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            _size[i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            if (find_set(a[i]) != find_set(b[i])) {
                union_sets(a[i], b[i]);
            }
        }
        int ans1 = 0;
        int ans2 = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == parent[i]) {
                ans1 += _size[i] - 1;
                ans2 = (1LL * ans2 * fact[_size[i]]) % M;
            }
        }
        ans2 = (1LL * ans2 * fact[ans1]) % M;
        if (k == 1) {
            cout << ans1 << "\n";
        }
        else {
            cout << ans1 << " " << ans2 << "\n";
        }
    }
    return 0;
}