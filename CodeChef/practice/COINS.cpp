#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

map<int, lli> dp;

lli f(int n) {
    lli res;
    if (dp[n] != 0) {
        res = dp[n];
    }
    else if (n == 0 || n == 1 || n == 2) {
        res = n;
    }
    else {
        res = dp[n] = max(f(n / 2) + f(n / 3) + f(n / 4), (lli)n);
    }
    return res;
}

int main() {
    int n;
    while (cin >> n) {
        cout << f(n) << '\n';
    }
    return 0;
}