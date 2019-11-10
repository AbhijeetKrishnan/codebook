#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum Colour { WHITE, GREY, BLACK };

template<typename T>
void debug(vector<T>& v, string s) {
    cout << s << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto ele: v) {
        cout << ele << " ";
    }
    cout << "\n";
}

void dfs(vector<vector<int>>& g, int root, int par, vector<int>& parent, vector<Colour>& colour, int skip, bool& contains_cycle) {
    if (colour[root] == Colour::BLACK) {
        return;
    }
    else if (colour[root] == Colour::GREY) {
        // cout << "root: " << root << " parent: " << par << "\n";
        contains_cycle = true;
        return;
    }
    parent[root] = par;
    colour[root] = Colour::GREY;
    for (int v: g[root]) {
        if (v == parent[root] or v == skip) {
            continue;
        }
        dfs(g, v, root, parent, colour, skip, contains_cycle);
    }
    colour[root] = Colour::BLACK;
}

bool contains_cycle(vector<vector<int>>& g, int n, int skip) {
    vector<int> parent(n);
    vector<Colour> colour(n, Colour::WHITE);
    vector<pair<int, int>> stack;
    bool _contains_cycle = false;
    for (int root = 0; root < n; root++) {
        if (colour[root] == Colour::BLACK or root == skip) {
            continue;
        }
        dfs(g, root, root, parent, colour, skip, _contains_cycle);
    }
    // debug(parent, "Parent");
    // debug(colour, "Colour");
    return _contains_cycle;
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        if (not contains_cycle(g, n, -1)) {
            cout << "-1\n";
            continue;
        }

        int failure = -1;
        for (int i = 0; i < n; i++) {
            // cout << "i: " << i << "\n";
            if (not contains_cycle(g, n, i)) {
                failure = i + 1;
                break;
            }
        }
        cout << failure << "\n";
    }
    return 0;
}