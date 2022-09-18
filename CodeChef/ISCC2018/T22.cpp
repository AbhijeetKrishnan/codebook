#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 100 + 1;

int main() {
    vector<bool> prime(N, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < N; (i == 2) ? ++i : i += 2) {
        for (int j = i + i; j < N; j += i) {
            prime[j] = false;
        }
    }
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (prime[v[i] * v[j]]) {
                    ans = min(ans, v[i] * v[j]);
                }
            }
        }
        if (ans == INT_MAX) {
            cout << "-1\n";
        }
        else {
            cout << ans << "\n";
        }
    }
    return 0;
}