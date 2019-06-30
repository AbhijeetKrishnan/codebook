#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5;

vector<int> g[N];
vector<int> path;
vector<int> rev_map(N, -1);
vector<int> bounds(N, -1);

int get_bounds(int root) {
    int ans = rev_map[root];
    for (auto v : g[root]) {
        ans = max(get_bounds(v), ans);
    }
    bounds[root] = ans;
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int tmp;
        cin >> tmp;
        g[tmp - 1].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
        reverse(g[i].begin(), g[i].end());
    }

    vector<int> stk;
    vector<bool> seen(n, false);
    stk.push_back(0);
    while (not stk.empty()) {
        int curr = stk.back();
        stk.pop_back();
        seen[curr] = true;
        path.push_back(curr);
        for (int v : g[curr]) {
            if (not seen[v]) {
                stk.push_back(v);
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        rev_map[path[i]] = i;
    }

    get_bounds(0);

    /*
    for (int i = 0; i < n; ++i) {
        cout << path[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < N; ++i) {
        if (rev_map[i] != -1) {
            cout << i << " " << rev_map[i] << "\n";
        }
    }
    for (int i = 0; i < N; ++i) {
        if (bounds[i] != -1) {
            cout << i << " " << bounds[i] << "\n";
        }
    }
    */

    while (q--) {
        int u, k;
        cin >> u >> k;
        u--;
        int ans;
        int len = bounds[u] - rev_map[u] + 1;
        if (len < k) {
            ans = -1;
        }
        else {
            int ind = rev_map[u] + k - 1;
            ans = path[ind] + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}