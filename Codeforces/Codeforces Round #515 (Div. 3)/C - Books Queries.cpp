#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    map<int, int> m;
    int left, right;
    left = right = 0;
    while (q--) {
        char c;
        int id;
        cin >> c >> id;
        if (c == 'L') {
            m[id] = left;
            if (left == 0) {
                left = -1;
                right = 1;
            }
            else {
                left--;
            }
        }
        else if (c == 'R') {
            m[id] = right;
            if (right == 0) {
                right = 1;
                left = -1;
            }
            else {
                right++;
            }
        }
        else if (c == '?') {
            int pos = m[id];
            int left_remove = pos - left - 1;
            int right_remove = right - pos - 1;
            int ans = min(left_remove, right_remove);
            cout << ans << "\n";
        }
    }
    return 0;
}