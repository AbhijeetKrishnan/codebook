#include <bits/stdc++.h>

using namespace std;

int T;
int n, m;
vector<vector<int>> g;
vector<pair<int, int>> edges;
set<pair<int, int>> is_bridge;

vector<bool> visited;
vector<int> tin, fup;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = fup[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                is_bridge.insert({v, to});
                is_bridge.insert({to, v});
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    fup.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}

pair<int, int> dfs2(int u, bool cyc_edge_seen) {
    //cout << u << " " << cyc_edge_seen << "\n";
    pair<int, int> res;
    if (cyc_edge_seen) {
        res = {0, 1};
    }
    else {
        res = {1, 0};
    }
    for (auto v: g[u]) {
        //cout << v << "\n";
        bool is_cyc_edge = is_bridge.count({u, v}) != 1;
        if (not visited[v] and (not cyc_edge_seen or not is_cyc_edge)) {
            visited[v] = true;
            res += dfs2(v, cyc_edge_seen or is_cyc_edge);
        }
    }
    return res;
}

int find_ans(int u, int v) {
    visited.assign(n, false);
    visited[u] = true;
    visited[v] = true;
    bool is_cyc_edge = is_bridge.count({u, v}) != 1;
    pair<int, int> a = dfs2(u, false);
    pair<int, int> b = dfs2(v, false);
    //cout << u << " " << v << " " << a << " " << b << "\n";
    if (is_cyc_edge)
        return a.first * b.first;
    else
        return a.first * b.first + a.first * b.second + a.second * b.first;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> T;
    for (int test = 0; test < T; test++) {
        g.clear();
        edges.clear();
        is_bridge.clear();
        cin >> n >> m;
        g.resize(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
            edges.push_back({u, v});
        }
        find_bridges();
        /*
        for (auto e: is_bridge) {
            //cout << e.first << " " << e.second << "\n";
        }
        */
        for (pair<int, int> e: edges) {
            cout << find_ans(e.first, e.second) << "\n";
        }
    }
    return 0;
}