#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s.insert(v[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto t = s.upper_bound(v[i]);
        if (t != s.end()) {
            ++ans;
            s.erase(t);
        }
    }
    cout << ans;
    return 0;
}