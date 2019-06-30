#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    vector<vector<char>> ans(50, vector<char>(50));
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 25; ++j) {
            ans[i][j] = 'A';
        }
    }
    for (int i = 0; i < 25; ++i) {
        for (int j = 25; j < 50; ++j) {
            ans[i][j] = 'B';
        }
    }
    for (int i = 25; i < 50; ++i) {
        for (int j = 0; j < 25; ++j) {
            ans[i][j] = 'C';
        }
    }
    for (int i = 25; i < 50; ++i) {
        for (int j = 25; j < 50; ++j) {
            ans[i][j] = 'D';
        }
    }
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 25; ++j) {
            if (i % 2 == 0 and j % 2 == 0) {
                if (d > 0) {
                    ans[i][j] = 'D';
                    d--;
                }
            }
        }
    }
    for (int i = 0; i < 25; ++i) {
        for (int j = 25; j < 50; ++j) {
            if (i % 2 == 0 and j % 2 == 0) {
                if (c > 0) {
                    ans[i][j] = 'C';
                    c--;
                }
            }
        }
    }
    for (int i = 25; i < 50; ++i) {
        for (int j = 0; j < 25; ++j) {
            if (i % 2 == 0 and j % 2 == 0) {
                if (b > 0) {
                    ans[i][j] = 'B';
                    b--;
                }
            }
        }
    }
    for (int i = 25; i < 50; ++i) {
        for (int j = 25; j < 50; ++j) {
            if (i % 2 == 0 and j % 2 == 0) {
                if (a > 0) {
                    ans[i][j] = 'A';
                    a--;
                }
            }
        }
    }
    cout << "50 50\n";
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}