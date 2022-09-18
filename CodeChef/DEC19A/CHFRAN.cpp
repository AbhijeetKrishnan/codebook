#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_tests;
    cin >> num_tests;
    for (int test = 0; test < num_tests; test++) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(2 * n);
        for (int i = 0; i < 2 * n; i += 2) {
            cin >> v[i].first;
            v[i].second = 0; 
            cin >> v[i + 1].first;
            v[i + 1].second = 1;
        }
        sort(v.begin(), v.end());
        int r;
        for (int i = 2 * n - 1; i >= 0; i--) {
            if (v[i].second == 0) {
                r = i;
                break;
            }
        }
        int ans = n;
        int curr = 1;
        for (int i = 1; i < r; i++) {
            if (v[i].second == 0) {
                curr++;
            }
            else {
                curr--;
                ans = min(ans, curr);
            }
        }
        if (ans == n) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}