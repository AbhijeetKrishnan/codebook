#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    long long s;
    cin >> n >> k >> s;
    if (s < k or s > 1LL * (n - 1) * k) {
        cout << "NO";
    }
    else {
        cout << "YES\n";
        vector<int> v(k, 1);
        long long curr = k;
        for (int i = 0; i < k; ++i) {
            v[i] += min(1LL * n - 2, s - curr);
            curr += v[i] - 1;
        }
        int pos = 1;
        for (int i = 0; i < k; ++i) {
            if (pos + v[i] <= n) {
                pos += v[i];
            }
            else {
                pos -= v[i];
            }
            cout << pos << " ";
        }
    }
    return 0;
}