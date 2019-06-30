#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string b[2];
    cin >> b[0];
    cin >> b[1];
    int n = b[0].length();
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        char& tl = b[0][i];
        char& tr = b[0][i+1];
        char& bl = b[1][i];
        char& br = b[1][i+1];

        if (tl == '0' and tr == '0' and bl == '0' and br == '0') {
            ans++;
            tl = tr = bl = 'X';
        }
        else if (tl == 'X' and tr == '0' and bl == '0' and br == '0') {
            ans++;
            tr = bl = br = 'X';
        }
        else if (tl == '0' and tr == 'X' and bl == '0' and br == '0') {
            ans++;
            tl = bl = br = 'X';
        }
        else if (tl == '0' and tr == '0' and bl == 'X' and br == '0') {
            ans++;
            tl = tr = br = 'X';
        }
        else if (tl == '0' and tr == '0' and bl == '0' and br == 'X') {
            ans++;
            tl = tr = bl = 'X';
        }
    }
    cout << ans;
    return 0;
}