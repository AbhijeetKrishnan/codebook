#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &e: a) {
            cin >> e;
        }
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                if (curr >= 0) curr += a[i];
                else curr -=a[i];
            }
            else {
                if (curr >= 0) curr -= a[i];
                else curr += a[i];
            }
        }
        if (curr >= k or curr <= -k) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}