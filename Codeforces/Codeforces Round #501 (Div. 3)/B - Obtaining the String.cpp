#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    vector<int> freq_s(26, 0), freq_t(26, 0);
    for (char c: s) {
        freq_s[c - 'a']++;
    }
    for (char c: t) {
        freq_t[c - 'a']++;
    }
    bool possible = true;
    for (int i = 0; i < 26; ++i) {
        if (freq_s[i] != freq_t[i]) {
            possible = false;
            break;
        }
    }
    if (not possible) {
        cout << "-1";
    }
    else {
        int cnt = 0;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                int j;
                for (j = i + 1; j < n and s[j] != t[i]; ++j) {}
                for (int k = j - 1; k >= i; --k) {
                    cnt++;
                    ans.push_back(k + 1);
                    swap(s[k], s[k+1]);
                }
            }
        }
        cout << cnt << "\n";
        for (int i: ans) {
            cout << i << " ";
        }
    }
    return 0;
}