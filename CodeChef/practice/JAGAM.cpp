#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int n, z1, z2;
        cin >> n >> z1 >> z2;
        vector<int> a(n);
        for (auto &e: a) {
            cin >> e;
        }
        int ans = -1;
        for (auto e: a) {
            if (abs(e) == abs(z1) or abs(e) == abs(z2)) {
                ans = 1;
                break;
            }
        }
        if (ans == -1) {
            ans = 2;
            for (auto e: a) {
                bool can_win = false;
                for (auto f: a) {
                    if (e + f == z1 or e + f == z2 or e - f == z1 or e - f == z2) {
                        can_win = true;
                    }
                }
                if (not can_win) {
                    ans = 0;
                }
                can_win = false;
                for (auto f: a) {
                    if (-e + f == z1 or -e + f == z2 or -e - f == z1 or -e - f == z2) {
                        can_win = true;
                    }
                }
                if (not can_win) {
                    ans = 0;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}