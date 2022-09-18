/**
 * Author: rashomon
 * Platform: Codechef
 * URL: https://www.codechef.com/AUG16/problems/CHEFRRUN
 * Problem Name: Chef and Round Run
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<int, vector<int>> graph;
typedef unordered_map<int, vector<pair<int, int>>> weighted_graph;
 
const int M = 1e9 + 7;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &e : v) {
            cin >> e;
        }
        int ans = 0;
        vector<int> parent(n, -1);
        vector<bool> seen(n, false);
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                int curr_parent = i;
                int curr_child = (i + v[i] + 1) % n;
                while (!seen[curr_child]) {
                    seen[curr_child] = true;
                    parent[curr_child] = curr_parent;
                    curr_parent = curr_child;
                    curr_child = (curr_parent + v[curr_parent] + 1) % n;
                }
                int count = 1;
                int ptr;
                for (ptr = curr_parent; ptr != -1 && ptr != curr_child; ptr = parent[ptr]) {
                    ++count;
                }
                if (ptr != -1) {
                    ans += count;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}