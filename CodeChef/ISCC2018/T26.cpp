#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> boxes(n, 0);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        boxes[l-1]++;
        if (r < n) {
            boxes[r]--;
        }
    }
    for (int i = 1; i < n; ++i) {
        boxes[i] += boxes[i-1];
    }
    sort(boxes.begin(), boxes.end());
    int q;
    cin >> q;
    for (int query = 0; query < q; query++) {
        int k;
        cin >> k;
        int ans = boxes.end() - lower_bound(boxes.begin(), boxes.end(), k);
        cout << ans << "\n";
    }
    return 0;
}