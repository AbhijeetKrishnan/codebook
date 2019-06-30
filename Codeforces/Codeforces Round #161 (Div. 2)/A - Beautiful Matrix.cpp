#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 5;
    int a[n][n];
    int ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                ans = abs(i - 2) + abs(j - 2);
            }
        }
    }
    cout << ans;
    return 0;
}