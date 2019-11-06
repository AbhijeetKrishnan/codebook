#include <iostream>
#include <vector>
#include <algorithm>
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
            int lb, ub;
            lb = ub = a[min_col][i];
            for (int j = 0; j < m; j++) {
                if (j == min_col) {
                    continue;
                }
                auto itr = lower_bound(a[j].begin(), a[j].end(), lb);
                if (itr == a[j].end()) {
                    itr--;
                    lb = *itr;
                }
            }
            for (int j = 0; j < m; j++) {
                if (j == min_col) {
                    continue;
                }
                auto itr = lower_bound(a[j].begin(), a[j].end(), lb);
                if (*itr > ub and itr == a[j].begin()) {
                    ub = *itr;
                }
            }
            for (int j = 0; j < m; j++) {
                if (j == min_col) {
                    continue;
                }
                auto itr = lower_bound(a[j].begin(), a[j].end(), lb);
                if (*itr > ub and itr != a[j].begin()) {
                    int min_ub, max_lb;
                    bool max_lb_exists = false;
                    min_ub = *itr;
                    itr--;
                    max_lb = *itr;
                    if (lb - max_lb < min_ub - ub) {
                        lb = max_lb;
                    }
                    else {
                        ub = min_ub;
                    }
                }
            }
            // printf("lb: %d, ub: %d\n", lb, ub);
            min_diff = min(min_diff, ub - lb);
        }
        cout << min_diff << "\n";
    }
    return 0;
}