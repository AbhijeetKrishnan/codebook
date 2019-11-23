#include <bits/stdc++.h>

using namespace std;

int modtiply(long long int a, long long int b, int m) {
    return (1LL * (a % m) * (b % m)) % m;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> factorial(m + 1);
    factorial[0] = 1;
    for (int i = 1; i <= m; i++) {
        factorial[i] = (1LL * factorial[i - 1] * i) % m;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        long long int p;
        cin >> p;
        int a, b;
        a = (p % 2 == 0) ? modtiply(modtiply(p / 2, p, m), p + 1, m) : modtiply(modtiply((p + 1) / 2, p, m), p, m);
        b = (p >= m) ? m - 1 : (factorial[p + 1] - 1 + m) % m;
        int f = (a + b) % m;
        ans = (ans + f) % m;
    }
    cout << ans << '\n';
    return 0;
}