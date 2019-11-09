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
        vector<int> s;
        vector<set<pair<int, int>>> back_edges(n);
        for (int root = 0; root < n; root++) {
            if (seen[root]) {
                continue;
            }
            parent[root] = root;
            height[root] = 0;
            s.push_back(root);
            while (not s.empty()) {
                int u = s.back(); s.pop_back();
                if (not seen[u]) {
                    seen[u] = true;
                    for (int v: g[u]) {
                        if (not seen[v]) {
                            parent[v] = u;
                            height[v] = height[u] + 1;
                            s.push_back(v);
                        }
                        else if (seen[v] and parent[u] != v) {
                            if (height[u] < height[v]) {
                                back_edges[v].insert({height[u], u});
                            }
                            else if (height[u] > height[v]) {
                                back_edges[u].insert({height[v], v});
                            }
                            else {
                                cout << "Should not happen with a DFS tree, I think\n";
                            }
                        }
                    }
                }
            }
        }

        // cout << "Parent\n";
        // for (int i = 0; i < n; i++) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < n; i++) {
        //     cout << parent[i] << " ";
        // }
        // cout << "\n";

        // cout << "Height\n";
        // for (int i = 0; i < n; i++) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < n; i++) {
        //     cout << height[i] << " ";
        // }
        // cout << "\n";

        // for (int i = 0; i < n; i++) {
        //     cout << i << ": ";
        //     for (auto p: back_edges[i]) {
        //         cout << "(" << p.second << ", " << p.first << ") ";
        //     }
        //     cout << "\n";
        // }
        
        for (int from = 0; from < n; from++) {
            int ptr = from;
            for (auto itr = back_edges[from].rbegin(); itr != back_edges[from].rend(); itr++) {
                while (ptr != itr->second) {
                    cycles[ptr]++;
                    ptr = parent[ptr];
                }
                if (ptr != from) {
                    cycles[ptr]++;
                }
            }
            if (back_edges[from].size() > 1)
                cycles[from] += back_edges[from].size() - 1;
        }

        int max_cycles = 0;
        for (int i = 0; i < n; i++) {
            max_cycles = max(max_cycles, cycles[i]);
        }   

        // cout << "Cycles\n";
        // for (int i = 0; i < n; i++) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < n; i++) {
        //     cout << cycles[i] << " ";
        // }
        // cout << "\n";

        int min_node;
        for (int i = 0; i < n; i++) {
            if (cycles[i] == max_cycles) {
                min_node = i;
                break;
            }
        }

        g[min_node].clear();
        for (int i = 0; i < n; i++) {
            if (i != min_node)
                if (g[i].find(min_node) != g[i].end())
                    g[i].erase(g[i].find(min_node));
        }

        bool cycle_present = false;
        fill(seen.begin(), seen.end(), false);
        s.clear();
        for (int root = 0; root < n and not cycle_present; root++) {
            if (seen[root]) {
                continue;
            }
            parent[root] = root;
            seen[root] = true;
            s.push_back(root);
            while (not s.empty() and not cycle_present) {
                int u = s.back(); s.pop_back();
                for (int v: g[u]) {
                    if (not seen[v]) {
                        seen[v] = true;
                        parent[v] = u;
                        s.push_back(v);
                    }
                    else if (seen[v] and parent[u] != v) {
                        cycle_present = true;
                        break;
                    }
                }
            }
        }

        if (cycle_present or cycles[min_node] == 0) {
            cout << "-1\n";
        }
        else {
            cout << min_node + 1 << "\n";
        }
    }
    return 0;
}