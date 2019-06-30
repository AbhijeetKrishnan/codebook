#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> v(n);
    for (auto &e: v) {
        cin >> e;
    }
    int max_l = -1;
    for (int i = 0; i <= min(n - 1, 0 + r - 1); i++) {
        if (v[i] == 1) {
            max_l = i;
        }
    }
    for (int i = max_l - 1; i >= 0; i--) {
        v[i] = 0;
    }
    int max_r = n;
    for (int i = n - 1; i >= max(0, n - 1 - r + 1); i--) {
        if (v[i] == 1) {
            max_r = i;
        }
    }
    for (int i = max_r + 1; i < n; i++) {
        v[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1) {
            int left = -1;
            for (int j = i - 1; j >= max(0, i - r + 1); j--) {
                if (v[j] == 1) {
                    left = j;
                    break;
                }
            }
            int right = n;
            for (int j = i + 1; j <= min(n - 1, i + r - 1); j++) {
                if (v[j] == 1) {
                    right = j;
                    break;
                }
            }
            if (left != -1 and max(0, i - r + 1) == max(0, left - r + 1)) {
                v[left] = 0;
            }
            if (right != n and min(n - 1, i + r - 1) == min(n - 1, right + r - 1)) {
                v[right] = 0;
            }
            if (left != -1 and right != n and v[left] == 1 and v[right] == 1) {
                v[i] = 0;
            }
        }
    }
    /*
    for (auto e: v) {
        cout << e << " ";
    }
    cout << "\n";
    */
    vector<bool> heated(n, false);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1) {
            cnt++;
            for (int j = max(i - r + 1, 0); j <= min(i + r - 1, n - 1); ++j) {
                heated[j] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (not heated[i]) {
            cout << "-1";
            return 0;
        }
    }
    cout << cnt;
    return 0;
}