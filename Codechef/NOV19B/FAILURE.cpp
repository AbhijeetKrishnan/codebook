#include <iostream>
#include <vector>
#include <deque>

using namespace std;

bool contains_cycle(vector<vector<int>>& g, int n, int skip) {
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

void find_cycles(vector<vector<int>>& g, int n, vector<int>& cycles) {
    vector<int> parent(n);
    vector<bool> seen(n, false);
    fill(cycles.begin(), cycles.end(), 0);
    vector<pair<int, int>> stack;
    for (int root = 0; root < n; root++) {
        if (seen[root]) {
            continue;
        }
        stack.push_back({root, root});
        while (not stack.empty()) {
            // cout << "Stack: ";
            // for (auto ele: stack) {
            //     cout << "(" << ele.first << ", " << ele.second << ") ";
            // }
            // cout << "\n";
            pair<int, int> tmp = stack.back(); stack.pop_back();
            int u = tmp.first;
            int p = tmp.second;
            // cout << "u: " << u << " p: " << p << "\n";
            
            if (not seen[u]) {
                seen[u] = true;
                parent[u] = p;
            }
            if (seen[u] and parent[u] != p) {
                int ptr = u;
                cycles[u]++;
                while (ptr != p) {
                    ptr = parent[ptr];
                    cycles[ptr]++;
                }
            }
            for (int v: g[u]) {
                if (not seen[v]) {
                    stack.push_back({v, u});
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        if (not contains_cycle(g, n, -1)) {
            cout << "-1\n";
            continue;
        }

        vector<int> cycles(n);
        find_cycles(g, n, cycles);
        int max_cycles = 0;
        for (int i = 0; i < n; i++) {
            max_cycles = max(max_cycles, cycles[i]);
        }

        int failure = -1;
        for (int i = 0; i < n; i++) {
            if (cycles[i] != max_cycles)
                continue;
            if (not contains_cycle(g, n, i)) {
                failure = i + 1;
                break;
            }
        }
        cout << failure << "\n";
    }
    return 0;
}