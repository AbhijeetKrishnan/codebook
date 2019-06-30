#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = i + p; j < n; j += p) {
            if (s[j] == '.' and s[j-p] == '.') {
                s[j - p] = '0';
                s[j] = '1';
            }
            else if (s[j] == '.' and s[j - p] != '.') {
                s[j] = '0' + (s[j - p] - '0') ^ 1;
            }
            else if (s[j] != '.' and s[j - p] == '.') {
                s[j - p] = '0' + (s[j] - '0') ^ 1;
            }
        }
        if (s[i] == '.') {
            s[i] = '0';
        }
    }
    bool ans = false;
    for (int i = 0; i + p < n; ++i) {
        bool valid = false;
        for (int j = i + p; j < n; j += p) {
            if (s[j] != s[j - p]) valid = true;
        }
        ans = ans or valid;
    }
    if (ans) {
        cout << s;
    }
    else {
        cout << "No";
    }
    return 0;
}