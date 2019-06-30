#include <bits/stdc++.h>

using namespace std;

template<class T>
void display_v(string msg, vector<T> v) {
    cout << msg << "\n";
    for (int i = 0; i < v.size(); ++i) {
        cout << i << "\t";
    }
    cout << "\n";
    for (auto i: v) {
        cout << i << "\t";
    }
    cout << "\n";
}

int n, m;
vector<vector<int>> g;
set<pair<int, int>> is_bridge;
vector<int> comp;

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
            if (fup[to] > tin[v])
                is_bridge.insert({v, to});
                is_bridge.insert({to, v});
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

void dfs2(int u) {
    //cout << u << "\n";
    visited[u] = true;
    for (auto v: g[u]) {
        if (not visited[v] and is_bridge.count({u, v}) != 1) {
            comp[v] = comp[u];
            dfs2(v);
        }
    }
}

vector<int> dist;

void dfs3(int u) {
    visited[u] = true;
    for (auto v: g[u]) {
        if (not visited[v]) {
            dist[v] = dist[u] + (comp[v] != comp[u]);
            dfs3(v);
        }
    }
}

int main() {
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    find_bridges();

    visited.assign(n, false);
    comp.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            //cout << i << "\n";
            comp[i] = i;
            dfs2(i);
        }
    }

    //display_v("comp", comp);

    visited.assign(n, false);
    dist.assign(n, 0);
    dfs3(comp[0]);

    //display_v("dist", dist);

    int max_index, max_val = -1;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > max_val) {
            max_val = dist[i];
            max_index = i;
        }
    }

    visited.assign(n, false);
    dist.assign(n, 0);
    assert(0 <= max_index and max_index < n);
    assert(0 <= comp[max_index] and comp[max_index] < n);
    dfs3(comp[max_index]);

    //display_v("dist", dist);

    max_val = -1;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > max_val) {
            max_val = dist[i];
        }
    }
    cout << max_val;
    return 0;
}