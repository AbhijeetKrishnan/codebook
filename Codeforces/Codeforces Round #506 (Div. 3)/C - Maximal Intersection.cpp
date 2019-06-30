#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> s(n);
    multiset<int> l, r;
    for (int i = 0; i < n; ++i) {
        cin >> s[i].first >> s[i].second;
        l.insert(s[i].first);
        r.insert(s[i].second);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        l.erase(l.find(s[i].first));
        r.erase(r.find(s[i].second));
        auto itr = l.rbegin();
        int max_l = *itr;
        auto itr2 = r.begin();
        int min_r = *itr2;
        //cout << i << " " << max_l << " " << min_r << "\n";
        ans = max(ans, min_r - max_l);
        l.insert(s[i].first);
        r.insert(s[i].second);
    }
    cout << ans;
    return 0;
}