#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

bool contains_cycle(vector<set<int>>& g, int n) {
    bool cycle_present = false;
    vector<int> parent(n);
    vector<bool> seen(n, false);
    deque<int> q;
    for (int root = 0; root < n and not cycle_present; root++) {
        // cout << "root: " << root << " seen[root]: " << seen[root] << "\n";
        if (seen[root]) {
            continue;
        }
        parent[root] = root;
        seen[root] = true;
        q.push_back(root);
        while (not q.empty() and not cycle_present) {
            int u = q.front(); q.pop_front();
            // cout << "u = " << u << "\n";
            for (int v: g[u]) {
                // cout << "u = " << u << " v = " << v << "\n";
                if (not seen[v]) {
                    seen[v] = true;
                    parent[v] = u;
                    q.push_back(v);
                }
                else if (seen[v] and parent[u] != v) {
                    cycle_present = true;
                    break;
                }
            }
        }
    }
    return cycle_present;
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
        
        if (not contains_cycle(g, n)) {
            cout << "-1\n";
            continue;
        }
        int fail = -1;
        for (int failure = 0; failure < n; failure++) {
            set<int> tmp(g[failure].begin(), g[failure].end());
            vector<int> back;
            g[failure].clear();
            for (int i = 0; i < n; i++) {
                if (i != failure)
                    if (g[i].find(failure) != g[i].end()) {
                        g[i].erase(g[i].find(failure));
                        back.push_back(i);
                    }
            }
            if (not contains_cycle(g, n)) {
                fail = failure + 1;
                break;
            }
            g[failure].insert(tmp.begin(), tmp.end());
            for (int i: back) {
                g[i].insert(failure);
            }
        }
        cout << fail << "\n";
    }
    return 0;
}