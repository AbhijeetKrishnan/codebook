#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> pre;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        cin >> n >> k;
        pre.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> pre[i+1];
            pre[i+1] += pre[i];
        }
        int ans = 0;
        for (int i = 1; i + k - 1 <= n; ++i) {
            ans = max(ans, pre[i+k-1] - pre[i-1]);
        }
        cout << ans << "\n";
    }
    return 0;
}