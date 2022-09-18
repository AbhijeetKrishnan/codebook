#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &e: v) {
            cin >> e;
        }
        bool found = false;
        for (int i = 0; i < n and not found; ++i) {
            if (v[i] == 1) {
                found = true;
            }
            for (int j = i + 1; j < n and not found; ++j) {
                if (__gcd(v[i], v[j]) == 1) {
                    found = true;
                }
            }
        }
        if (found) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}