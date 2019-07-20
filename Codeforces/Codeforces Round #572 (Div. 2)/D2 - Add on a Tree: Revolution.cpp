#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <functional>
#include <unordered_map>

using namespace std;

typedef unordered_map<int, vector<pair<int, int>>> graph;
typedef tuple<int, int, int> op;

pair<int, int> find_two_leaves(graph& tree, int root, int parent) {
    vector<int> leaf(2);
    vector<bool> seen(tree.size(), false);
    function<int(int)> dfs = [&](int v) {
        seen[v] = true;
        for (auto [adj, _]: tree[v]) {
            if (not seen[adj]) {
                return dfs(adj);
            }
        }
        //cout << v << " ";
        return v;
    };
    seen[root] = true;
    seen[parent] = true;
    for (int i = 0; i < 2; i++) {
        for (auto [v, _]: tree[root]) {
            if (not seen[v]) {
                leaf[i] = dfs(v);
                break;
            }
        }
    }
    //cout << leaf[0] << " " << leaf[1] << "\n";
    return {leaf[0], leaf[1]};
}

void find_ops(graph& tree, vector<int>& degree, vector<op> edges, vector<op>& ans) {
    for (auto [u, v, w]: edges) {
        if (degree[v] == 1) {
            swap(u, v);
        }
        vector<int> leaves;
        int leaf_v1, leaf_v2;
        tie(leaf_v1, leaf_v2) = find_two_leaves(tree, v, u);
        if (degree[u] == 1) {
            ans.push_back({u + 1, leaf_v1 + 1, w / 2});
            ans.push_back({u + 1, leaf_v2 + 1, w / 2});
            ans.push_back({leaf_v1 + 1, leaf_v2 + 1, -w / 2});
        }
        else {
            leaves.clear();
            int leaf_u1, leaf_u2;
            tie(leaf_u1, leaf_u2) = find_two_leaves(tree, u, v);
            ans.push_back({leaf_u1 + 1, leaf_v1 + 1, w / 2});
            ans.push_back({leaf_u2 + 1, leaf_v2 + 1, w / 2});
            ans.push_back({leaf_u1 + 1, leaf_u2 + 1, -w / 2});
            ans.push_back({leaf_v1 + 1, leaf_v2 + 1, -w / 2});
        }
    }
}

int main() {
    int n;
    cin >> n;
    graph tree;
    vector<op> edges;
    vector<int> degree(n, 0);
    for (int i = 0; i + 1 < n; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        tree[u].push_back({v, x});
        tree[v].push_back({u, x});
        degree[u]++;
        degree[v]++;
        edges.push_back({u, v, x});
    }
    bool possible = true;
    for (int i: degree) {
        if (i == 2) {
            possible = false;
            break;
        }
    }
    if (not possible) {
        cout << "NO";
    }
    else {
        cout << "YES\n";
        if (n == 2) {
            cout << "1\n1 2 " << tree[0][0].second;
        }
        else {
            // preprocess tree to find 3 leaves in different subtrees for every non-leaf node

            // find_ops
            vector<op> ans;
            find_ops(tree, degree, edges, ans);
            cout << ans.size() << "\n";
            for (auto [u, v, w]: ans) {
                cout << u << " " << v << " " << w << "\n";
            }
        }
    }
    return 0;
}