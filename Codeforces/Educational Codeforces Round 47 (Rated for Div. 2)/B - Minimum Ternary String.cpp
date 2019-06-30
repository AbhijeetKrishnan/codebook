#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int i;
    for (i = 0; i < n && s[i] != '2'; ++i) {
        if (s[i] == '0') {
            cout << "0";
        }
    }
    for (int j = 0; j < n; ++j) {
        if (s[j] == '1') {
            cout << "1";
        }
    }
    for (; i < n; ++i) {
        if (s[i] != '1')
            cout << s[i];
    }
    return 0;
}