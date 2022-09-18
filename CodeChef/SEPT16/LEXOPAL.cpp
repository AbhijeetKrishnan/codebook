/**
 * Author: rashomon
 * Platform: Codechef
 * URL: https://www.codechef.com/SEPT16/problems/LEXOPAL
 * Problem Name: Faded Palindromes
 */

#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<int, vector<int>> graph;
typedef unordered_map<int, vector<pair<int, int>>> weighted_graph;

const int M = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool ans = true;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if (s[i] == '.' && s[j] != '.') s[i] = s[j];
            else if (s[i] != '.' && s[j] == '.') s[j] = s[i];
            else if (s[i] == '.' && s[j] == '.') s[i] = s[j] = 'a';
            else if (s[i] != s[j]) {
                ans = false;
                break;
            }
        }
        if (s[n >> 1] == '.') s[n >> 1] = 'a';
        if (ans) cout << s << '\n';
        else cout << "-1\n";
    }
    return 0;
}