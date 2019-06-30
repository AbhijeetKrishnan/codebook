#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    vector<bool> is_max(n, false);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        //cout << v[i] << " ";
        ans += v[i].first;
        is_max[v[i].second] = true;
    }
    cout << ans << "\n";
    vector<int> cnt(n, 0);
    for (int i = 0; i < k; ++i) {
        int count = 0;
        int ind = v[i].second;
        //cout << ind << "\n";
        for (int i = ind - 1; i >= 0 and (not is_max[i]); --i) {
            ++count;
            is_max[i] = true;
        }
        for (int i = ind + 1; i < n and (not is_max[i]); ++i) {
            ++count;
            is_max[i] = true;
        }
        ++count;
        cnt[v[i].second] = count;
    }
    for (int i = 0; i < n; ++i) {
        if (cnt[i] != 0) {
            cout << cnt[i] << " ";
        }
    }
    return 0;
}