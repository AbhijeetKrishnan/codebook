#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int n;
        cin >> n;
        vector<bool> seen(n, false);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            a--;
            if (a >= n or seen[a]) {
                ans++;
            }
            else {
                seen[a] = true;
            }
        }
        cout << ans << "\n";
    }
}