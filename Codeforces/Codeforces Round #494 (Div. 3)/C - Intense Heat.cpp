#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i-1] + a[i-1];
    }
    double ans = 0;
    for (int len = k; len <= n; ++len) {
        for (int l = 0, r = l + len - 1; r < n; ++l, ++r) {
            double hi = (double)(pre[r + 1] - pre[l]) / (r - l + 1);
            ans = max(ans, hi);
        }
    }
    printf("%.20f", ans);
}