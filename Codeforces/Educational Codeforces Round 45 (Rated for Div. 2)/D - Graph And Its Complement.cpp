#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a > 1 and b > 1) {
        cout << "NO";
    }
    else if ((n == 2 or n == 3) and a == 1 and b == 1) {
        cout << "NO";
    }
    else {
        cout << "YES\n";
        vector<vector<int>> v(n, vector<int>(n, 1));
        if (a == 1 and b == 1) {
            v.assign(n, vector<int>(n, 0));
            for (int i = 0; i + 1 < n; ++i) {
                v[i][i+1] = 1;
                v[i+1][i] = 1;
            }
        }
        else if (b == 1) {
            for (int i = 0; i + 1 < a; ++i) {
                for (int j = 0; j < n; ++j) {
                    v[i][j] = 0;
                    v[j][i] = 0;
                }
            }
        }
        else {
            for (int i = 0; i + 1 < b; ++i) {
                for (int j = 0; j < n; ++j) {
                    v[i][j] = 0;
                    v[j][i] = 0;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    v[i][j] ^= 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            v[i][i] = 0;
        }
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << v[i][j];
                }
                cout << "\n";
            }
    }
    return 0;
}