/**
 * Author: MystikNinja
 * Platform: Codeforces
 * URL: http://codeforces.com/contest/690/problem/D1
 * Problem Name: The Wall (easy)
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> v(r);
    for (auto &e : v) {
        cin >> e;
    }
    int ans = 0;
    string bottom = v[r-1];
    int i = 0;
    while (i < c) {
        if (bottom[i] == 'B') {
            ++ans;
            while (i < c && bottom[i] == 'B') 
                ++i;
        }
        else 
            ++i;
    }
    cout << ans;
    return 0;
}
