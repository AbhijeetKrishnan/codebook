#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int INF = 1e9;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(m, vector<int>());
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            a[i % m].push_back(tmp);
        }
        int min_col = m - 1;
        for (int i = 0; i < m; i++) {
            sort(a[i].begin(), a[i].end());
            if (a[i].size() < a[min_col].size())
                min_col = i;
        }
        int min_diff = INF;
        for (int i = 0; i < a[min_col].size(); i++) {
            int max_ub, min_lb;
            max_ub = min_lb = a[min_col][i];
            bool ub_poss = true, lb_poss = true;
            for (int j = 0; j < m; j++) {
                if (j == min_col) {
                    continue;
                }
                auto itr = lower_bound(a[j].begin(), a[j].end(), a[min_col][i]);
                if (itr != a[j].end()) {
                    max_ub = max(max_ub, *itr);
                }
                else {
                    max_ub = max(max_ub, *a[j].rbegin());
                    lb_poss = false;
                }
                itr = upper_bound(a[j].begin(), a[j].end(), a[min_col][i]);
                if (itr != a[j].begin()) {
                    itr--;
                    min_lb = min(min_lb, *itr);
                }
                else {
                    min_lb = min(min_lb, *a[j].begin());
                    ub_poss = false;
                }
            }
            if (lb_poss) {
                printf("Assuming lower bound: lb: %d ub: %d\n", a[min_col][i], max_ub);
                min_diff = min(min_diff, max_ub - a[min_col][i]);
            }
            if (ub_poss) {
                printf("Assuming upper bound: lb: %d ub: %d\n", min_lb, a[min_col][i]);
                min_diff = min(min_diff, a[min_col][i] - min_lb);
            }
            printf("Assuming in between range: lb: %d, ub: %d\n", min_lb, max_ub);
            min_diff = min(min_diff, max_ub - min_lb);
        }
        cout << min_diff << "\n";
    }
    return 0;
}