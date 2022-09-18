#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        int l = 0;
        bool swapped = false;
        for (int k = n - 1; k > 0; k--) {
            for (int i = 0, j = k; j > i; i++) {
                int actual_val = swapped ? a[j][i] : a[i][j];
                int expected_val = i * n + j + 1;
                if (actual_val != expected_val) {
                    // cout << "-" << k << '\n';
                    swapped = not swapped;
                    l++;
                    break;
                }
            }
        }
        cout << l << '\n';
    }
    return 0;
}