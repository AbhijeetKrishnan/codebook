#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (toupper(s[i]) > toupper(t[i])) {
            ans = 1;
            break;
        }
        else if (toupper(s[i]) < toupper(t[i])) {
            ans = -1;
            break;
        }
    }
    cout << ans;
    return 0;
}