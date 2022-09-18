#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<vector<int>> ans;
 
void shift(char dir) {
    if (dir != 'L' and dir != 'R' and dir != 'U' and dir != 'D') {
        return;
    }
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ans[i][j] == 1) {
                row[i]++;
                col[j]++;
            }
        }
    }
    ans.assign(n, vector<int>(m, 0));
    if (dir == 'L') {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < row[i]; ++j) {
                ans[i][j] = 1;
            }
        }
    }
    else if (dir == 'R') {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < row[i]; ++j) {
                ans[i][m - j - 1] = 1;
            }
        }
    }
    else if (dir == 'U') {
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < col[j]; ++i) {
                ans[i][j] = 1;
            }
        }
    }
    else if (dir == 'D') {
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < col[j]; ++i) {
                ans[n - i - 1][j] = 1;
            }
        }
    }
}
 
int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        cin >> n >> m;
        vector<string> a(n);
        for (auto &e: a) {
            cin >> e;
        }
        ans.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '1') {
                    ans[i][j] = 1;
                }
            }
        }
        string d;
        cin >> d;
        shift(d[0]);
        char latest_ud = '.', latest_lr = '.';
        int ind_ud = -1, ind_lr = -1;
        for (int i = 1; i < d.length(); ++i) {
            if (d[i] == 'U' or d[i] == 'D') {
                latest_ud = d[i];
                ind_ud = i;
            }
            else {
                latest_lr = d[i];
                ind_lr = i;
            }
        }
        if (ind_ud < ind_lr) {
            shift(latest_ud);
            shift(latest_lr);
        }
        else {
            shift(latest_lr);
            shift(latest_ud);
        }
        //cout << d << "\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}