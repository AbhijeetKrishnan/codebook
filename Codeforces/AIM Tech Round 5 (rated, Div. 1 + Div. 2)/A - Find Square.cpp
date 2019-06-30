#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &e: v) {
        cin >> e;
    }
    int l, r, t, b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 'B') {
                t = i;
                l = j;
                goto outer;
            }
        }
    }
outer: for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (v[i][j] == 'B') {
                b = i;
                r = j;
                goto outer2;
            }
        }
    }
    outer2: cout << (t + b + 2) / 2 << " " << (l + r + 2) / 2;
    return 0;
}