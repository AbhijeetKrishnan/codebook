#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << s;
    }
    else if (s.size() == 2) {
        if (s[0] == s[1]) {
            if (s[0] == 'a') {
                s[1] = 'b';
            }
            else {
                s[1] = 'a';
            }
        }
        cout << s;
    }
    else {
        for (int i = 0; i + 2 < s.size(); ++i) {
            if (s[i] == s[i+1] && s[i+1] == s[i+2]) {
                if (s[i] == 'a') {
                    s[i+1] = 'b';
                }
                else {
                    s[i+1] = 'a';
                }
            }
            else if (s[i] == s[i+1]) {
                if (s[i+1] == 'a') {
                    s[i] = 'b';
                }
                else {
                    s[i] = 'a';
                }
            }
            else if (s[i+1] == s[i+2]) {
                if (s[i+1] == 'a') {
                    s[i+2] = 'b';
                }
                else {
                    s[i+2] = 'a';
                }
            }
        }
        cout << s;
    }
    return 0;
}
