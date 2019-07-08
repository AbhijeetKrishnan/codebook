#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ones = 0, zeros = 0;
    for (char c: s) {
        if (c == '0') {
            zeros++;
        }
        else {
            ones++;
        }
    }
    if (ones == zeros) {
        cout << "2\n";
        cout << s[0] << " " << s.substr(1);
    }
    else {
        cout << "1\n" << s;
    }
    return 0;
}