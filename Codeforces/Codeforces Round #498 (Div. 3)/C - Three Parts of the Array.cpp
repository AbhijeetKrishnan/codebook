#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i-1] + v[i-1];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long sum1 = pre[i+1] - pre[0];
        int lo = i + 1;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            long long sum3 = pre[n] - pre[mid];
            //cout << i << " " << sum1 << " " << mid << " " << sum3 << "\n";
            if (sum3 == sum1) {
                ans = max(sum1, ans);
                break;
            }
            else if (sum3 < sum1) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
    }
    cout << ans;
    return 0;
}