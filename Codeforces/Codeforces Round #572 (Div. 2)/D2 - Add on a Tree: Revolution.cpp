#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unordered_map<int, vector<pair<int, int>>> graph;
typedef tuple<int, int, int> op;

void find_all_leaves(graph& tree, int root, int parent, vector<int>& leaves) {
    stack<int> s;
    s.push(root);
    vector<bool> seen(tree.size(), false);
    seen[root] = true;
    seen[parent] = true;
    while (not s.empty()) {
        int u = s.top();
        s.pop();
        bool expanded = false;
        for (auto [v, _]: tree[u]) {
            if (not seen[v]) {
                seen[v] = true;
                s.push(v);
                expanded = true;
            }
        }
        if (not expanded) {
            leaves.push_back(u);
        }
    }
    // printf("Leaves (%d <- %d): ", parent, root);
    // for (auto leaf: leaves) {
    //     cout << leaf << " ";
    // }
    // cout << "\n";
}

void find_ops(graph& tree, vector<int>& degree, vector<op> edges, vector<op>& ans) {
    for (auto [u, v, w]: edges) {
        //printf("Calculating ops for edge (%d - %d)", u, v);
        if (degree[v] == 1) {
            swap(u, v);
        }
        vector<int> leaves;
        find_all_leaves(tree, v, u, leaves);
        int leaf_v1 = leaves[0];
        int leaf_v2 = leaves[1];
        if (degree[u] == 1) {
            ans.push_back({u + 1, leaf_v1 + 1, w / 2});
            ans.push_back({u + 1, leaf_v2 + 1, w / 2});
            ans.push_back({leaf_v1 + 1, leaf_v2 + 1, -w / 2});
        }
        else {
            leaves.clear();
            find_all_leaves(tree, u, v, leaves);
            int leaf_u1 = leaves[0];
            int leaf_u2 = leaves[1];
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