#include <bits/stdc++.h>

using namespace std;

const int LIM = 31;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> two_pows;
    for (int i = 0; i < LIM; ++i) {
        two_pows.push_back(1 << i);
    }
    set<int> s;
    for (int i = 0; i < LIM; ++i) {
        for (int j = i + 1; j < LIM; ++j) {
            s.insert(two_pows[i] + two_pows[j]);
        }
    }
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n;
        cin >> n;
        auto itr = s.lower_bound(n);
        int ans;
        if (itr != s.begin()) {
            ans = min(n - *(--itr), *itr - n);
        }
        else {
            ans = *itr - n;
        }
        cout << ans << "\n";
    }
    return 0;
}