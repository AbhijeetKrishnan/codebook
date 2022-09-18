#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        string m, n;
        cin >> m >> n;
        int sum_m = 0, sum_n = 0;
        for (char c : m) {
            sum_m += (int)(c - '0');
        }
        for (char c : n) {
            sum_n += (int)(c - '0');
        }
        int ans = ((sum_m % 3) * (sum_n % 3)) % 3;
        cout << ans << "\n";
    }
    return 0;
}