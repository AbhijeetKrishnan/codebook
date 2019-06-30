#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<char, int> a[4], b[4];
    for (int i = 0; i < 4; ++i) {
        a[i]['M'] = 0;
        a[i]['S'] = 0;
        a[i]['L'] = 0;
        b[i]['M'] = 0;
        b[i]['S'] = 0;
        b[i]['L'] = 0;
    }
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        a[tmp.length() - 1][tmp[tmp.length() - 1]]++;
    }
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        b[tmp.length() - 1][tmp[tmp.length() - 1]]++;
    }
    int ans = 0;
    for (int sz = 0; sz < 4; ++sz) {
        ans += abs(a[sz]['M'] - b[sz]['M']) + abs(a[sz]['L'] - b[sz]['L']) + abs(a[sz]['S'] - b[sz]['S']);
    }
    ans /= 2;
    cout << ans;
    return 0;
}