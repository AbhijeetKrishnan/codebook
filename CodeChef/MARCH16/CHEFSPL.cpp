#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool ans;
        if (n & 1) {
            if (n == 1) {
                ans = false;
            }
            else {
                bool ans1 = true, deleted1 = false;
                for (int i = 0, j = n / 2; j < n && ans1; ++i, ++j) {
                    if (s[i] != s[j] && !deleted1) {
                        deleted1 = true;
                        --i;
                    }
                    else if (s[i] != s[j] && deleted1) {
                        ans1 = false;
                    }
                }
                bool ans2 = true, deleted2 = false;
                for (int i = 0, j = n / 2 + 1; j < n && ans2; ++i, ++j) {
                    if (s[i] != s[j] && !deleted2) {
                        deleted2 = true;
                        --j;
                    }
                    else if (s[i] != s[j] && deleted2) {
                        ans2 = false;
                    }
                }
                ans = (ans1 || ans2);
            }
        }
        else {
            ans = true;
            for (int i = 0, j = n / 2; j < n && ans; ++i, ++j) {
                if (s[i] != s[j]) {
                    ans = false;
                }
            }
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}