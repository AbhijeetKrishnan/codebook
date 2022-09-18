#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> freq1(26, 0), freq2(26, 0);
        for (int i = 0; i < (n>>1); ++i) {
            ++freq1[s[i] - 'a'];
        }
        for (int i = (n>>1) + (n & 1); i < n; ++i) {
            ++freq2[s[i] - 'a'];
        }
        bool is_same = true;
        for (int i = 0; i < 26 && is_same; ++i) {
            if (freq1[i] != freq2[i]) {
                is_same = false;
            }
        }
        if (is_same) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}