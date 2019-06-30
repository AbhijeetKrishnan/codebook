#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<long long>> v(2, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        cin >> v[0][i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[1][i];
    }
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i - 1] + v[0][i - 1] + v[1][i - 1];
    }
    vector<long long> cycle_sum(n);
    if (n & 1) {
        cycle_sum[n - 1] = 2 * (n - 1) * v[0][n - 1] + (2 * n - 1) * v[1][n - 1];
        for (int i = n - 3; i >= 0; i -= 2) {
            cycle_sum[i] = cycle_sum[i + 2] - 2 * (pre[n] - pre[i + 2]) + 2 * i * v[0][i] + (2 * i + 1) * v[0][i + 1] + (2 * n - 1) * v[1][i] + (2 * n - 2) * v[1][i + 1];
        }
        if (n > 1) {
            cycle_sum[n - 2] = (2*n - 1) * v[0][n - 2] + (2*n - 2) * v[0][n - 1] + (2*n - 3) * v[1][n - 1] + (2*n - 4) * v[1][n - 2];
        }
        for (int i = n - 4; i >= 0; i -= 2) {
            cycle_sum[i] = cycle_sum[i + 2] - 2 * (pre[n] - pre[i + 2]) + 2 * i * v[1][i] + (2 * i + 1) * v[1][i + 1] + (2 * n - 1) * v[0][i] + (2 * n - 2) * v[0][i + 1];
        }
    }
    else {
        cycle_sum[n - 1] = 2 * (n - 1) * v[1][n - 1] + (2 * n - 1) * v[0][n - 1];
        for (int i = n - 3; i >= 0; i -= 2) {
            cycle_sum[i] = cycle_sum[i + 2] - 2 * (pre[n] - pre[i + 2]) + 2 * i * v[1][i] + (2 * i + 1) * v[1][i + 1] + (2 * n - 1) * v[0][i] + (2 * n - 2) * v[0][i + 1];
        }
        cycle_sum[n - 2] = (2*n - 1) * v[1][n - 2] + (2*n - 2) * v[1][n - 1] + (2*n - 3) * v[0][n - 1] + (2*n - 4) * v[0][n - 2];
        for (int i = n - 4; i >= 0; i -= 2) {
            cycle_sum[i] = cycle_sum[i + 2] - 2 * (pre[n] - pre[i + 2]) + 2 * i * v[0][i] + (2 * i + 1) * v[0][i + 1] + (2 * n - 1) * v[1][i] + (2 * n - 2) * v[1][i + 1];
        }
    }
    long long ans = 0;
    long long curr = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, curr + cycle_sum[i]);
        if (i & 1) {
            curr += 2 * i * v[1][i] + (2 * i + 1) * v[0][i];
        }
        else {
            curr += 2 * i * v[0][i] + (2 * i + 1) * v[1][i];
        }
    }
    cout << ans;
    return 0;
}