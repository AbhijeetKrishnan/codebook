#include <bits/stdc++.h>

using namespace std;

const int N = 5000;

int n, m, s;
vector<int> g[N], gt[N], scc[N];
int u, v;
vector<bool> visited(N, false);
deque<int> stk;
vector<int> comp(N, -1);
int ctr = 0;
vector<int> indeg(N, 0);
vector<bool> seen(N, false);

void visit(int root) {
    if (!visited[root]) {
        visited[root] = true;
        for (auto nbr : g[root]) {
            visit(nbr);
        }
        stk.push_front(root);
    }
}

void assign(int u) {
    comp[u] = ctr;
    for (auto v : gt[u]) {
        if (comp[v] == -1) {
            assign(v);
        }
    }
}

int main() {
    cin >> n >> m >> s;
    s--;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        gt[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; ++i) {
        visit(i);
    }

    for (auto u : stk) {
        if (comp[u] == -1) {
            assign(u);
            ctr++;
        }
    }

    for (int u = 0; u < n; ++u) {
        for (auto v : g[u]) {
            if (comp[u] != comp[v]) {
                scc[comp[u]].push_back(comp[v]);
                indeg[comp[v]]++;
            }
        }
    }

    stk.clear();
    stk.push_back(comp[s]);
    while (!stk.empty()) {
        int curr = stk.back();
        stk.pop_back();
        if (!seen[curr]) {
            seen[curr] = true;
            for (auto nbr : scc[curr]) {
                stk.push_back(nbr);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < ctr; ++i) {
        if (!seen[i] && indeg[i] == 0) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}