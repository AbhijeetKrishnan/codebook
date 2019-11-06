#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

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
        int min_diff = INT_MAX;
        for (int i = 0; i < a[min_col].size(); i++) {
            int lb, ub;
            lb = ub = a[min_col][i];
            for (int j = 0; j < m; j++) {
                if (j == min_col) {
                    continue;
                }
                int curr_diff = INT_MAX;
                auto closest_itr = upper_bound(a[j].begin(), a[j].end(), a[min_col][i]);
                int closest;
                if (closest_itr != a[j].end()) {
                    if (curr_diff > abs(*closest_itr - a[min_col][i])) {
                        curr_diff = abs(*closest_itr - a[min_col][i]);
                        closest = *closest_itr;
                    }
                }
                if (closest_itr != a[j].begin()) {
                    closest_itr--;
                    if (curr_diff > abs(*closest_itr - a[min_col][i])) {
                        curr_diff = abs(*closest_itr - a[min_col][i]);
                        closest = *closest_itr;
                    }
                }
                lb = (closest < lb) ? closest : lb;
                ub = (closest > ub) ? closest : ub;
            }
            min_diff = min(min_diff, ub - lb);
        }
        cout << min_diff << "\n";
    }
    return 0;
}