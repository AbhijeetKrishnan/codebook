#include <bits/stdc++.h>

using namespace std;

const int N = 400000;

int n, d, k;
vector<vector<int>> g(N + 1);

vector<bool> seen(N, false);
deque<int> q;
vector<int> dist(N, -1);

void display() {
    q.push_back(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop_front();
        seen[curr-1] = true;
        for (auto v : g[curr]) {
            if (!seen[v-1]) {
                cout << curr << " " << v << "\n";
                q.push_back(v);
            }
        }
    }
}

int diameter() {
    q.push_back(1);
    dist[0] = 0;
    int max_d = 0;
    int max_i;
    while (!q.empty()) {
        int curr = q.front();
        q.pop_front();
        //cout << curr << "\n";
        for (auto e : g[curr]) {
            //cout << e << " " << dist[e-1] << "\n";
            if (dist[e-1] == -1) {
                q.push_back(e);
                dist[e-1] = dist[curr-1] + 1;
                if (dist[e-1] > max_d) {
                    max_d = dist[e-1];
                    max_i = e;
                }
            }
        }
    }
    //cout << max_i << " " << max_d << "\n";
    dist.assign(n, -1);
    dist[max_i-1] = 0;
    q.push_back(max_i);
    max_d = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop_front();
        for (auto e : g[curr]) {
            if (dist[e-1] == -1) {
                q.push_back(e);
                dist[e-1] = dist[curr-1] + 1;
                if (dist[e-1] > max_d) {
                    max_d = dist[e-1];
                }
            }
        }
    }
    return max_d;
}

bool solve() {
    bool is_possible = true;
    if (d > n - 1) {
        is_possible = false;
    }
    else if (k == 1) {
        is_possible = false;
    }
    if (is_possible) {
        int ctr = 1;
        for (int i = 0; i < d / 2 + d % 2; ++i) {
            g[ctr].push_back(++ctr);
            g[ctr].push_back(ctr-1);

        }
        for (int i = 0; i < d / 2; ++i) {
            if (i == 0) {
                g[1].push_back(++ctr);
                g[ctr].push_back(1);
            }
            else {
                g[ctr].push_back(++ctr);
                g[ctr].push_back(ctr-1);
            }
        }
        q.push_back(1);
        while (ctr < n && !q.empty()) {
            int curr = q.front();
            q.pop_front();
            while (ctr < n && g[curr].size() < k) {
                g[curr].push_back(++ctr);
                g[ctr].push_back(curr);
            }
            for (auto e : g[curr]) {
                q.push_back(e);
            }
        }
        q.clear();
        //display();
        //cout << diameter() << "\n";
        if (diameter() != d) {
            is_possible = false;
        }
    }
    //cout << is_possible << "\n";
    return is_possible;
}

int main() {
    cin >> n >> d >> k;
    if (solve()) {
        cout << "YES\n";
        display();
    }
    else {
        cout << "NO\n";
    }
    return 0;
}