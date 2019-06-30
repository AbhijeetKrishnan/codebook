#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    //cout << s << " " << t;
    int i;
    for (i = 0; i < min((int)s.length(), (int)t.length()) && s[i] == t[i]; ++i) {
    }
    //cout << i << "\n";
    int ans = max((int)s.length() - i, 0) + max((int)t.length() - i, 0);
    cout << ans;
    return 0;
}