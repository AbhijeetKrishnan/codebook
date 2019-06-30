#include <bits/stdc++.h>

using namespace std;

const int N = 3000;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(N, vector<int>());
    multiset<int> s;
    int curr_items = 0;
    for (int i = 0; i < n; ++i) {
        int p_i, c_i;
        cin >> p_i >> c_i;
        if (p_i != 1) {
            p_i--;
            mp[p_i].push_back(c_i);
            s.insert(c_i);
        }
        else {
            curr_items++;
        }
    }
    int lvl = 0;
    for (int i = 0; i < N; ++i) {
        sort(mp[i].begin(), mp[i].end(), greater<int>());
        lvl = max(lvl, (int)mp[i].size());
    }
    long long int ans = -1;
    long long int curr_lvl = 0;
    while (lvl > 0 and lvl + 1 > curr_items) {
        auto itr = s.begin();
        long long int curr = 0;
        for (int i = 0; i < (int)s.size() and i < lvl + 1 - curr_items; ++i, ++itr) {
            curr += *itr;
        }
        if (ans == -1)
            ans = curr + curr_lvl;
        else
            ans = min(ans, curr + curr_lvl);
        for (int i = 1; i < N; ++i) {
            if ((int)mp[i].size() == lvl) {
                curr_lvl += mp[i].back();
                s.erase(s.find(mp[i].back()));
                mp[i].pop_back();
                curr_items++;
            }
        }
        lvl--;
    }
    if (ans == -1) ans = 0;
    cout << ans;
    return 0;
}