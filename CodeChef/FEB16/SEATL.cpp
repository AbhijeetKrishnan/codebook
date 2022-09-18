#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

struct entry {
    vector<int> row_max, col_max;
    int max_row_count = 0, max_col_count = 0;
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int v[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &v[i][j]);
            }
        }
        unordered_map<int, entry> tb;
        vector<unordered_map<int, int>> row(n), col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val_row = ++row[i][v[i][j]], val_col = ++col[j][v[i][j]];
                if (val_row > tb[v[i][j]].max_row_count) {
                    tb[v[i][j]].row_max.clear();
                    tb[v[i][j]].max_row_count = val_row;
                    tb[v[i][j]].row_max.push_back(i);
                }
                else if (val_row == tb[v[i][j]].max_row_count) {
                    tb[v[i][j]].row_max.push_back(i);
                }
                if (val_col > tb[v[i][j]].max_col_count) {
                    tb[v[i][j]].col_max.clear();
                    tb[v[i][j]].max_col_count = val_col;
                    tb[v[i][j]].col_max.push_back(j);
                }
                else if (val_col == tb[v[i][j]].max_col_count) {
                    tb[v[i][j]].col_max.push_back(j);
                }
            }
        }
        int ans = 0;
        for (auto ele : tb) {
            if (ans < ele.second.max_row_count + ele.second.max_col_count) {
                if (v[ele.second.row_max[0]][ele.second.col_max[0]] == ele.first) {
                    int l1 = ele.second.row_max.size(), l2 = ele.second.col_max.size();
                    bool in_intersection = true;
                    for (int i = 0; i < l1 && in_intersection; i++) {
                        for (int j = 0; j < l2 && in_intersection; j++) {
                            if (v[ele.second.row_max[i]][ele.second.col_max[j]] != ele.first) {
                                in_intersection = false;
                            }
                        }
                    }
                    if (in_intersection) {
                        ans = max(ans, ele.second.max_row_count + ele.second.max_col_count - 1);
                    }
                    else {
                        ans = max(ans, ele.second.max_row_count + ele.second.max_col_count);
                    }
                }
                else {
                    ans = max(ans, ele.second.max_row_count + ele.second.max_col_count);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}