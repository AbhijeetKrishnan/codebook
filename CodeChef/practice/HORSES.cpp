#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &e : v) {
            cin >> e;
        }
        sort(v.begin(), v.end());
        int min = 1e9;
        for (int i = 1; i < n; ++i) {
            int curr_diff = v[i] - v[i-1];
            if (curr_diff < min) {
                min = curr_diff;
            }
        }
        cout << min << '\n';
    }
    return 0;
}