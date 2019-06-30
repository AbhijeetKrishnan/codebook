/**
 * Author: MystikNinja
 * Platform: Codeforces
 * URL: http://codeforces.com/contest/690/problem/C1
 * Problem Name: Brain Network (easy)
 */

#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<int, vector<int>> graph;
typedef unordered_map<int, vector<pair<int, int>>> weighted_graph;

const int M = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    graph g;
    vector<bool> seen(n, false);
    vector<int> parent(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool has_cycle = false;
    seen[0] = true;
    parent[0] = 1;
    stack<int> s;
    s.push(1);
    while (!s.empty()) {
         int curr = s.top();
        s.pop();
        for (int e : g[curr]) {
            if (!seen[e-1]) {
                seen[e-1] = true;
                parent[e-1] = curr;
                s.push(e);
            }
            else if (e != parent[curr-1] && parent[e-1] != curr) {
                //cout << e << " " << curr << '\n';
                has_cycle = true;
            }
        }
    }
    bool is_reachable = true;
    for (bool b : seen) {
        if (b != true) {
            is_reachable = false;
        }
    }
    bool is_valid = !has_cycle && is_reachable;
    /*
    for (auto e : seen) {
        cout << e << ' ';
    }
    cout << '\n';
    for (auto e : parent) {
        cout << e << ' ';
    }
    cout << '\n';
    */
    if (is_valid) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    return 0;
}
