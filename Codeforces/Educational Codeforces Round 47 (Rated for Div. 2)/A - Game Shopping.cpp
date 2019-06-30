#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n), a(m);
    for (auto &e : c) {
        cin >> e;
    }
    for (auto &e : a) {
        cin >> e;
    }
    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[j] >= c[i]) {
            ++ans;
            ++i;
            ++j;
        }
        else {
            ++i;
        }
    }
    cout << ans;
    return 0;
}