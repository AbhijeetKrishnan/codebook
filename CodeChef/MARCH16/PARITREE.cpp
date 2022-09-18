#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<int, vector<pair<int, int>>> graph;
const int lo = 0, hi = 1;
const int M = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i < n; ++i) {
            int to, from;
            cin >> to >> from;
        }
        graph g;
        vector<int> u(q), v(q), k(q);
        for (int i = 0; i < q; ++i) {
            cin >> u[i] >> v[i] >> k[i];
            g[u[i]].push_back(make_pair(v[i], k[i]));
            g[v[i]].push_back(make_pair(u[i], k[i]));
        }
        int ans = 1;
        vector<int> weights(n, -1);
        vector<bool> seen(n, false);
        weights[0] = lo;
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                if (i != 0)
                    ans = (2LL * ans) % M;
                //cout << i << " " << ans << '\n';
                weights[i] = 0;
                queue<int> q;
                q.push(i + 1);
                seen[i] = true;
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    for (auto ele : g[curr]) {
                        if (!seen[ele.first - 1]) {
                            weights[ele.first - 1] = weights[curr - 1] ^ ele.second;
                            seen[ele.first - 1] = true;
                            q.push(ele.first);
                        }
                    }
                }
            }
        }
        bool impossible = false;
        for (int i = 0; i < q && !impossible; ++i) {
            if ((weights[u[i] - 1] ^ weights[v[i] - 1]) != k[i]) {
                impossible = true;
            }
        }
        if (impossible) {
            ans = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}