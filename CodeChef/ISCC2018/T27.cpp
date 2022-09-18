#include <bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &e: v) {
            cin >> e;
        }
        unordered_map<long long, int> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long long val = 1LL * v[i] * v[i] + 1LL * v[j] * v[j];
                if (m.count(val) == 0) {
                    m[val] = 1;
                }
                else {
                    m[val]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long long val = 1LL * v[i] * v[i] + v[j];
                if (m.count(val) > 0) {
                    ans += m[val];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}