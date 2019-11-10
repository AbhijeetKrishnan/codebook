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

void dfs(vector<vector<int>>& g, int u, int p, vector<int>& parent, vector<int>& colour, vector<int>& cycles) {
    if (colour[u] == 2) {
        return;
    }
    if (colour[u] == 1) {
        int curr = p;
        cycles[curr]++;
        while (curr != u) {
            curr = parent[curr];
            cycles[curr]++;
        }
        return;
    }
    parent[u] = p;
    colour[u] = 1;
    for (auto v: g[u]) {
        if (v == parent[u]) {
            continue;
        }
        dfs(g, v, u, parent, colour, cycles);
    }
    colour[u] = 2;
}

void find_cycles(vector<vector<int>>& g, vector<int>& cycles) {
    int n = g.size();
    vector<int> parent(n);
    vector<int> colour(n, 0);
    fill(cycles.begin(), cycles.end(), 0);
    for (int root = 0; root < n; root++) {
        if (colour[root] == 2) {
            continue;
        }
        dfs(g, root, root, parent, colour, cycles);
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
        vector<int> cycles(n, 0);
        find_cycles(g, cycles);

        int max_cycles = 0;
        for (int i = 0; i < n; i++) {
            max_cycles = max(max_cycles, cycles[i]);
        }

        int failure = -1;
        for (int i = 0; i < n; i++) {
            if (cycles[i] != max_cycles) {
                continue;
            }
            if (not contains_cycle(g, n, i)) {
                failure = i + 1;
                break;
            }
        }
        cout << failure << "\n";
    }
    return 0;
}