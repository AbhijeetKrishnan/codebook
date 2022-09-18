#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<pair<int, int>> parent(N);
vector<int> _rank(N);
vector<bool> bipartite(N);

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    _rank[v] = 0;
    bipartite[v] = true;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

void add_edge(int a, int b) {
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            bipartite[a] = false;
    } else {
        if (_rank[a] < _rank[b])
            swap(a, b);
        parent[b] = make_pair(a, x^y^1);
        bipartite[a] = bipartite[a] and bipartite[b];
        if (_rank[a] == _rank[b])
            ++_rank[a];
    }
}

bool is_bipartite(int v) {
    return bipartite[find_set(v).first];
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<int> teeth(n);
    for (auto &e: teeth) {
        cin >> e;
    }
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    for (int query = 0; query < m; ++query) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, c;
            cin >> x >> c;
            teeth[--x] = c;
        }
        else if (t == 2) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            add_edge(x, y);
        }
        else {
            int x, y, v;
            cin >> x >> y >> v;
            x--, y--;
            long long num, den;
            pair<int, int> x_root = find_set(x);
            pair<int, int> y_root = find_set(y);
            if (is_bipartite(x) and is_bipartite(y) and x_root.first == y_root.first) {
                num = 1LL * v * teeth[x];
                den = teeth[y];
                long long g = __gcd(num, den);
                num /= g;
                den /= g;
                if ((x_root.second ^ y_root.second) == 1) {
                    num = -num;
                }
                cout << num << "/" << den << "\n";
            }
            else {
                cout << "0" << "\n";
            }
        }
    }
    return 0;
}