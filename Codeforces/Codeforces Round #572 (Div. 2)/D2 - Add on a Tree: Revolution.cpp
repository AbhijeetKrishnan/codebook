#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unordered_map<int, vector<pair<int, int>>> graph;
typedef pair<pair<int, int>, int> op;

void find_all_leaves(graph& tree, int root, int parent, vector<int>& leaves) {
    stack<int> s;
    s.push(root);
    vector<bool> seen(tree.size(), false);
    seen[root] = true;
    seen[parent] = true;
    while (not s.empty()) {
        int curr = s.top();
        s.pop();
        bool expanded = false;
        for (auto e: tree[curr]) {
            if (not seen[e.first]) {
                seen[e.first] = true;
                s.push(e.first);
                expanded = true;
            }
        }
        if (not expanded) {
            leaves.push_back(curr);
        }
    }
    // printf("Leaves (%d <- %d): ", parent, root);
    // for (auto leaf: leaves) {
    //     cout << leaf << " ";
    // }
    // cout << "\n";
}

int solve(graph& tree, vector<int>& parent, int root, vector<op>& ans) {
    int res = 0;
    int n = tree.size();
    stack<int> s;
    vector<bool> seen(n, false);
    s.push(root);
    seen[root] = true;
    while (not s.empty()) {
        int curr = s.top();
        s.pop();
        for (auto e: tree[curr]) {
            if (not seen[e.first]) {
                s.push(e.first);
                seen[e.first] = true;
                int u = curr;
                int v = e.first;
                int w = e.second;
                //printf("Calculating ops for edge (%d - %d)", u, v);
                // find leaf in graph from v not including u-v edge
                vector<int> target_leaves;
                find_all_leaves(tree, v, u, target_leaves);
                int target_leaf = target_leaves[0];
                //printf("Target leaf: %d", target_leaf);
                // find leaf in graph from u not including u-v edge
                vector<int> other_leaves;
                find_all_leaves(tree, u, v, other_leaves);
                int leaf_1 = other_leaves[0];
                // find another leaf in graph from u not including u-v edge
                int leaf_2 = other_leaves[1];
                //printf("Other leaves: %d, %d", leaf_1, leaf_2);
                ans.push_back({{target_leaf + 1, leaf_1 + 1}, w / 2});
                ans.push_back({{target_leaf + 1, leaf_2 + 1}, w / 2});
                ans.push_back({{leaf_1 + 1, leaf_2 + 1}, -w / 2});
                res += 3;
                // subtract edge_val from all edges in path from tree[root][i].first to target_leaf
                int curr = target_leaf;
                while (curr != v) {
                    for (auto &e: tree[parent[curr]]) {
                        if (e.first == curr) {
                            e.second -= w;
                            curr = parent[curr];
                            break;
                        }
                    }
                }
            }
        }
    }
    return res;
}

void dfs(graph& g, int root, vector<int>& parent) {
    stack<int> s;
    vector<bool> seen(g.size(), false);
    s.push(root);
    seen[root] = true;
    parent[root] = root;
    while (not s.empty()) {
        int curr = s.top();
        s.pop();
        for (auto e: g[curr]) {
            if (not seen[e.first]) {
                //printf("Seeing edge %d -> %d\n", curr, e.first);
                seen[e.first] = true;
                s.push(e.first);
                parent[e.first] = curr;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    graph tree;
    vector<int> degree(n, 0);
    for (int i = 0; i + 1 < n; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        tree[u].push_back({v, x});
        tree[v].push_back({u, x});
        degree[u]++;
        degree[v]++;
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
            cout << "1 2 " << tree[0][0].second;
        }
        else {
            // create rooted tree with non-leaf vertex v as root
            int nonleaf_vertex;
            for (int i = 0; i < n; i++) {
                if (degree[i] != 1) {
                    nonleaf_vertex = i;
                    break;
                }
            }
            //cout << nonleaf_vertex << "\n";
            vector<int> parent(n);
            dfs(tree, nonleaf_vertex, parent);
            // printf("Parent: ");
            // for (int i = 0; i < n; i++) {
            //     printf("(%d <- %d)\n", parent[i], i);
            // }
            // preprocess tree to find 3 leaves in different subtrees for every non-leaf node

            // solve
            vector<op> ans;
            int num_operations = solve(tree, parent, nonleaf_vertex, ans);
            cout << num_operations << "\n";
            for (auto e: ans) {
                cout << e.first.first << " " << e.first.second << " " << e.second << "\n";
            }
        }
    }
    return 0;
}