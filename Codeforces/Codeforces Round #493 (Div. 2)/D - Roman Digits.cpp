#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<bool>> broken(9, vector<bool>(49, false));
long long ans;

int main() {
    cin >> n;
    for (int x = 0; x <= 8; ++x) {
        for (int y = 0; y <= 48; ++y) {
            for (int p = 0; p <= 8; ++p) {
                for (int q = 0; q <= 48; ++q) {
                    if (((4 * x + 9 * y) > (4 * p + 9 * q)) and (((4 * x + 9 * y) - (4 * p + 9 * q)) % 49 == 0)) {
                        //cout << x << " " << y << " " << p << " " << q << "\n";
                        broken[x][y] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= min(8, n); ++i) {
        for (int j = 0; i + j <= n and j <= min(48, n); ++j) {
            if (not broken[i][j]) {
                ans += n - i - j + 1;
            }
        }
    }
    cout << ans;
    return 0;
}