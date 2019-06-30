#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    //cout << s;
    int ans = s[0] - 'a' + 1;
    int num = 1;
    for (int i = 1, prev = 0; i < n and num < k; ++i) {
        if (s[i] - s[prev] >= 2) {
            //cout << i << "\n";
            ans += s[i] - 'a' + 1;
            num++;
            prev = i;
        }
    }
    if (num != k) {
        cout << "-1";
    }
    else {
        cout << ans;
    }
    return 0;
}