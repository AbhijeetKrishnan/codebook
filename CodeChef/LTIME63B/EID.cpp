#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &e: v) {
            cin >> e;
        }
        sort(v.begin(), v.end());
        int ans = INT_MAX;
        for (int i = 1; i < n; ++i) {
            ans = min(ans, v[i] - v[i-1]);
        }
        cout << ans << "\n";
    }
    return 0;
}