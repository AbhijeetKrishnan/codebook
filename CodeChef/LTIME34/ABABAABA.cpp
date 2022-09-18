#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int a_cnt = 0, b_cnt = 0;
        for (char c : s) {
            if (c == 'A') {
                ++a_cnt;
            }
            else {
                ++b_cnt;
            }
        }
        if (a_cnt == 2) {
            cout << "A\n";
        }
        else if (b_cnt == 2) {
            cout << "B\n";
        }
        else {
            bool found = false;
            for (int i = 0; i + 3 < n && !found; ++i) {
                if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'B' && s[i + 3] == 'A') {
                    for (int j = 0; j <= i; ++j) {
                        cout << s[j];
                    }
                    cout << "B";
                    for (int j = i + 3; j < n; ++j) {
                        cout << s[j];
                    }
                    found = true;
                }
                else if (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'A' && s[i + 3] == 'B') {
                    for (int j = 0; j <= i; ++j) {
                        cout << s[j];
                    }
                    cout << "A";
                    for (int j = i + 3; j < n; ++j) {
                        cout << s[j];
                    }
                    found = true;
                }
            }
            if (!found) {
                if (n > 2 && s[0] == s[1] && s[1] != s[2]) {
                    for (int i = 1; i < n; ++i) {
                        cout << s[i];
                    }
                }
                else if (n > 2 && s[n - 1] == s[n - 2] && s[n - 2] != s[n - 3]) {
                    for (int i = 0; i + 1 < n; ++i) {
                        cout << s[i];
                    }
                }
                else {
                    cout << "-1\n";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}