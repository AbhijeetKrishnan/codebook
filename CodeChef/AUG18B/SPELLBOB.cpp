#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        vector<string> cards(2);
        cin >> cards[0];
        cin >> cards[1];
        bool possible = false;
        for (int i = 0; i < 8 and not possible; ++i) {
            int b_cnt = 0;
            int o_cnt = 0;
            for (int j = 0; j < 3; ++j) {
                char c = cards[(i >> j) & 1][j];
                if (c == 'b') b_cnt++;
                else if (c == 'o') o_cnt++;
            }
            if (b_cnt == 2 and o_cnt == 1) possible = true;
        }
        if (possible) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    return 0;
}