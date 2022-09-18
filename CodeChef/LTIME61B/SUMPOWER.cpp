#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int change[n] = {0};
        string s;
        cin >> s;
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i-1]) {
                change[i] = 1;
            }
        }
        for (int i = 1; i < n; ++i) {
            change[i] += change[i-1];
        }
        long long int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += (long long int)(change[i+n-k] - change[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}