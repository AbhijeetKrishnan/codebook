#include <bits/stdc++.h>

using namespace std;
typedef unordered_map<int, vector<int>> graph;

int main() {
    int n, m;
    cin >> n >> m;
    graph g;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> seen(n, false);
    vector<int> parent(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!seen[i]) {
            bool has_cycle = false;
            parent[i] = i + 1; //root
            seen[i] = true;
            stack<int> s;
            s.push(i + 1);
            while (!s.empty()) {
                int curr = s.top();
                s.pop();
                for (auto e : g[curr]) {
                    if (!seen[e - 1]) {
                        s.push(e);
                        seen[e - 1] = true;
                        parent[e - 1] = curr;
                    }
                    else if (parent[curr - 1] != e) {
                        //cout << "Check: " << e << " " << curr << '\n';
                        has_cycle = true;
                    }
                }
            }
            if (!has_cycle) {
                ++ans;
            }
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " " << seen[i] << " " << parent[i] << '\n';
    }
    */
    cout << ans;
    return 0;
}
