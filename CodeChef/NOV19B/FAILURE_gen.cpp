#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

int rand_range(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int t = 1;
    cout << t << "\n";
    for (int test = 0; test < t; test++) {
        int n = rand_range(1, 10);
        int m = rand_range(n - 1, min(n + 1, n * (n - 1) / 2));
        cout << n << " " << m << "\n";
        vector<set<int>> g(n);
        vector<int> visited = {0};
        vector<int> unvisited;
        for (int i = 1; i < n; i++) {
            unvisited.push_back(i);
        }
        int visited_cnt = 1, unvisited_cnt = n - 1;
        int edges = 0;
        while (not unvisited.empty()) {
            int vis_idx = rand_range(0, visited_cnt - 1);
            int unvis_idx = rand_range(0, unvisited_cnt - 1);
            cout << visited[vis_idx] + 1 << " " << unvisited[unvis_idx] + 1 << "\n";
            edges++;
            g[visited[vis_idx]].insert(unvisited[unvis_idx]);
            g[unvisited[unvis_idx]].insert(visited[vis_idx]);
            visited.push_back(unvisited[unvis_idx]);
            visited_cnt++;
            unvisited.erase(unvisited.begin() + unvis_idx);
            unvisited_cnt--;
        }
        while (edges < m) {
            int u = rand_range(0, n - 1);
            int v = rand_range(0, n - 1);
            if (u != v and g[u].find(v) == g[u].end()) {
                edges++;
                cout << u + 1 << " " << v + 1 << "\n";
                g[u].insert(v);
                g[v].insert(u);
            }
        }
    }
    return 0;
}