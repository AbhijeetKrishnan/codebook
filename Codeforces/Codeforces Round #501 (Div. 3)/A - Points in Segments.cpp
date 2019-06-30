#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= m; ++i) {
        bool valid = true;
        for (int j = 0; j < n; ++j) {
            if (i >= v[j].first and i <= v[j].second) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cnt++;
            ans.push_back(i);
        }
    }
    cout << cnt << "\n";
    for (int i: ans) {
        cout << i << " ";
    }
    return 0;
}