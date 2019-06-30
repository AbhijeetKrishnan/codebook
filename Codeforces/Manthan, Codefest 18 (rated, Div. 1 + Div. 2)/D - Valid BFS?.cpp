#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    vector<int> a(n);
    for (auto &e: a) {
        cin >> e;
        e--;
    }
    bool is_valid = true;
    if (a[0] != 0) {
        is_valid = false;
    }
    else {
        int i = 0, j = 1;
        while (j < n) {
            if (not is_permutation(g[a[i]].begin(), g[a[i]].end(), a.begin() + j)) {
                is_valid = false;
                break;
            }
            else {
                j += (int)g[a[i]].size();
                i++;
            }
        }
    }
    if (is_valid) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}