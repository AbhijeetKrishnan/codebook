#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int LIM = 1e5;

int t;
int n, m;
vector<int> g[LIM];
int parent[LIM];
int cycles[LIM];
int colour[LIM];
bool seen[LIM];

bool contains_cycle(int skip) {
    for (int i = 0; i < n; i++) {
        seen[i] = false;
    }
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

void dfs(int u, int p) {
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
        dfs(v, u);
    }
    colour[u] = 2;
}

void find_cycles() {
    for (int root = 0; root < n; root++) {
        dfs(root, root);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    for (int test = 0; test < t; test++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            g[i].clear();
            cycles[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        if (not contains_cycle(-1)) {
            cout << "-1\n";
            continue;
        }

        find_cycles();

        int max_cycles = 0;
        for (int i = 0; i < n; i++) {
            max_cycles = max(max_cycles, cycles[i]);
        }

        int failure = -1;
        for (int i = 0; i < n; i++) {
            if (cycles[i] != max_cycles) {
                continue;
            }
            if (not contains_cycle(i)) {
                failure = i + 1;
                break;
            }
        }
        cout << failure << "\n";
    }
    return 0;
}