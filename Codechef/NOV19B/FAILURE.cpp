#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

bool contains_cycle(vector<set<int>>& g, int n, int skip) {
    vector<int> parent(n);
    vector<bool> seen(n, false);
    deque<int> q;
    for (int root = 0; root < n; root++) {
        if (seen[root] or root == skip) {
            continue;
        }
        parent[root] = root;
        seen[root] = true;
        q.push_back(root);
        while (not q.empty()) {
            int u = q.front(); q.pop_front();
            for (int v: g[u]) {
                if (v == skip) {
                    continue;
                }
                if (not seen[v]) {
                    seen[v] = true;
                    parent[v] = u;
                    q.push_back(v);
                }
                else if (seen[v] and parent[u] != v) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n, m;
        cin >> n >> m;
        vector<set<int>> g(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].insert(v);
            g[v].insert(u);
        }
        
        if (not contains_cycle(g, n, -1)) {
            cout << "-1\n";
            continue;
        }
        int failure = -1;
        for (int i = 0; i < n; i++) {
            if (not contains_cycle(g, n, i)) {
                failure = i + 1;
                break;
            }
        }
        cout << failure << "\n";
    }
    return 0;
}