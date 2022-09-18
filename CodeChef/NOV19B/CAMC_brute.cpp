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
        for (int i = 0; i < m; i++) {
            sort(a[i].begin(), a[i].end());
        }
        int min_diff = INF;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                int lb, ub;
                lb = a[i][j];
                ub = -1;
                for (int k = 0; k < m; k++) {
                    if (k == i) {
                        continue;
                    }
                    auto itr = lower_bound(a[k].begin(), a[k].end(), a[i][j]);
                    if (itr != a[k].end()) {
                        ub = max(ub, *itr);
                    }
                    else {
                        ub = -1;
                        break;
                    }
                }
                //printf("lb: %d ub: %d\n", lb, ub);
                if (ub != -1)
                    min_diff = min(min_diff, ub - lb);
            }
        }
        cout << min_diff << "\n";
    }
    return 0;
}