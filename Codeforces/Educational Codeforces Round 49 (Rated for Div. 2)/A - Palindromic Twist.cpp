#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool valid = true;
        for (int i = 0, j = n - 1; valid and i < j; ++i, --j) {
            if (abs(s[i] - s[j]) != 2 and abs(s[i] - s[j]) != 0) {
                valid = false;
            }
        }
        if (valid) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}