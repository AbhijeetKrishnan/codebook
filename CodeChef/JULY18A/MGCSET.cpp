#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n, m;
        cin >> n >> m;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            if (tmp % m == 0) {
                ++count;
            }
        }
        //cout << count << "\n";
        int ans = (1 << count) - 1;
        cout << ans << "\n";
    }
    return 0;
}