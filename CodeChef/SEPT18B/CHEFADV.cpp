#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        if ((n - 1) % x == 0 and (n - 1) / x >= 0 and (m - 1) % y == 0 and (m - 1) / y >= 0) {
            cout << "Chefirnemo\n";
        }
        else if ((n - 2) % x == 0 and (n - 2) / x >= 0 and (m - 2) % y == 0 and (m - 2) / y >= 0) {
            cout << "Chefirnemo\n";
        }
        else {
            cout << "Pofik\n";
        }
    }
    return 0;
}