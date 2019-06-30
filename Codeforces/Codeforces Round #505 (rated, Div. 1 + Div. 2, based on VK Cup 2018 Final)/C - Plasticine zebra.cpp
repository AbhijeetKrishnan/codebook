#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = (int)s.length();
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1] and s[0] != s[n - 1]) {
            reverse(s.begin(), s.begin() + (i + 1));
            reverse(s.begin() + (i + 1), s.end());
            //cout << i << " " << s << "\n";
        }
    }
    int ans = 0;
    int curr_len = 1;
    char curr_char = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] != curr_char) {
            curr_len++;
            curr_char = s[i];
        }
        else {
            ans = max(ans, curr_len);
            curr_len = 1;
        }
    }
    ans = max(ans, curr_len);
    cout << ans;
    return 0;
}