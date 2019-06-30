/**
 * Author: MystikNinja
 * Platform: Codeforces
 * URL: http://codeforces.com/contest/690/problem/F1
 * Problem Name: Tree of Life (easy)
 */

#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<int, vector<int>> graph;
typedef unordered_map<int, vector<pair<int, int>>> weighted_graph;

const int M = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    graph g;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    uint64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j : g[i]) {
            //cout << i << ' ' << g[i].size() << ' ' << j << ' ' << g[j].size() << ' ' << ans << '\n';
            ans += g[j].size() - 1;
        }
    }
    ans >>= 1;
    cout << ans;
    return 0;
}
