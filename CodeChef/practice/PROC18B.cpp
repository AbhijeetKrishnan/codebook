#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        double ans = a[0];
        for (int i = 1; i < n; ++i) {
            ans = (ans + a[i]) / 2;
        }
        printf("%.10f\n", ans);
    }
    return 0;
}