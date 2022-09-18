#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long int m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (auto &e: a) {
        cin >> e;
    }
    for (auto &e: b) {
        cin >> e;
    }
    long long int lo = 1, hi = 1e18;
    while (lo < hi) {
        long long int mid = (lo + hi) / 2;
        long long int total = 0;
        for (int i = 0; i < n; ++i) {
            long long int num = 1LL * a[i] * b[i] - mid;
            long long int x;
            if (num < 0) {
                x = 0;
            }
            else {
                x = num / b[i] + ((num % b[i]) == 0 ? 0 : 1);
            }
            total += x;
        }
        if (total <= m) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << lo;
    return 0;
}