/**
 * Author: rashomon
 * Platform: Codechef
 * URL: https://www.codechef.com/AUG16/problems/CHEFCRUN
 * Problem Name: Chef and Circle Run
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
        int start, end;
        cin >> start >> end;
        --start, --end;
        
        int64_t go_sum = 0;
        for (int i = start; i != end; i = (i + 1) % n) {
            go_sum += v[i];
        }
        int64_t total = 0;
        int64_t max_so_far, max_ending_here;
        
        max_so_far = max_ending_here = 0;
        for (int i = (start - 1 + n) % n; i != (end - 1 + n) % n; i = (i - 1 + n) % n) {
            total += 2 * v[i];
            max_ending_here = max((int64_t)0, max_ending_here + v[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }
        //cout << "Cost1 -\n";
        //cout << go_sum << " " << total << " " << max_so_far << '\n';
        int64_t cost1 = go_sum + total - 2 * max_so_far;

        go_sum = 0;
        for (int i = (start - 1 + n) % n; i != (end - 1 + n) % n; i = (i - 1 + n) % n) {
            go_sum += v[i];
        }
        total = 0;
        max_so_far = max_ending_here = 0;
        for (int i = start; i != end; i = (i + 1) % n) {
            total += 2 * v[i];
            max_ending_here = max((int64_t)0, max_ending_here + v[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }
        //cout << "Cost2 -\n";
        //cout << go_sum << " " << total << " " << max_so_far << '\n';
        int64_t cost2 = go_sum + total - 2 * max_so_far;

        int64_t ans = min(cost1, cost2);
        cout << ans << '\n';
    }
    return 0;
}