#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

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
        vector<int> parent(n), cycles(n, 0), height(n);
        vector<bool> seen(n, false);
        deque<int> q;
        for (int root = 0; root < n; root++) {
            if (seen[root]) {
                continue;
            }
            parent[root] = root;
            seen[root] = true;
            height[root] = 0;
            q.push_back(root);
            while (not q.empty()) {
                int u = q.front(); q.pop_front();
                for (int v: g[u]) {
                    if (not seen[v]) {
                        seen[v] = true;
                        parent[v] = u;
                        height[v] = height[u] + 1;
                        q.push_back(v);
                    }
                    else if (seen[v] and parent[u] != v) {
                        int _u = u, _v = v;
                        // cout << "_u = " << _u << " _v = " << _v << "\n";
                        do {
                            if (height[_u] > height[_v]) {
                                cycles[_u]++;
                                _u = parent[_u];
                            }
                            else if (height[_u] < height[_v]) {
                                cycles[_v]++;
                                _v = parent[_v];
                            }
                            else {
                                cycles[_u]++;
                                _u = parent[_u];
                                cycles[_v]++;
                                _v = parent[_v];
                            }
                        } while (_u != _v and g[_u].find(_v) == g[_u].end());
                        if (_u == _v) {
                            cycles[_u]++;
                        }
                        else {
                            cycles[_u]++;
                            cycles[_v]++;
                        }
                    }
                }
            }
        }
        
        int max_cycles = 0;
        for (int i = 0; i < n; i++) {
            cycles[i] >>= 1;
            max_cycles = max(max_cycles, cycles[i]);
        }

        /*
        cout << "Parent\n";
        for (int i = 0; i < n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << parent[i] << " ";
        }
        cout << "\n";

        cout << "Cycles\n";
        for (int i = 0; i < n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << cycles[i] << " ";
        }
        cout << "\n";

        cout << "Height\n";
        for (int i = 0; i < n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << height[i] << " ";
        }
        cout << "\n";
        */

        int min_node;
        for (int i = 0; i < n; i++) {
            if (cycles[i] == max_cycles) {
                min_node = i;
                break;
            }
        }
        // cout << "min_node: " << min_node << "\n";
        g[min_node].clear();
        for (int i = 0; i < n; i++) {
            if (i != min_node)
                if (g[i].find(min_node) != g[i].end())
                    g[i].erase(g[i].find(min_node));
        }

        bool cycle_present = false;
        fill(seen.begin(), seen.end(), false);
        q.clear();
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
        
        // cout << "cycle_present = " << cycle_present << "\n";

        if (cycle_present or cycles[min_node] == 0) {
            cout << "-1\n";
        }
        else {
            cout << min_node + 1 << "\n";
        }
    }
    return 0;
}