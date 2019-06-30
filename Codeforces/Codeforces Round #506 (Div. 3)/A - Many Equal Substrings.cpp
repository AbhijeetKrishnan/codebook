#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    cout << t;
    int mn = n;
    for (int i = n - 1; i > 0; --i) {
        int j;
        for (j = i; j < n and t[j] == t[j - i]; ++j) {
        }
        if (j == n) {
            mn = min(mn, i);
        }
    }
    //cout << mn << "\n";
    for (int i = 1; i < k; ++i) {
        cout << t.substr(n - mn);
    }
    return 0;
}