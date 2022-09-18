/**
 * Author: rashomon
 * Platform: Codechef
 * URL: https://www.codechef.com/LTIME39/problems/ALPHABET
 * Problem Name: Studying Alphabet
 */
 
#include <bits/stdc++.h>

using namespace std;

int main() {
    string known;
    cin >> known;
    vector<bool> is_known(26, false);
    for (char c : known) {
        is_known[c - 'a'] = true;
    }
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        bool can_read = true;
        for (char c : s) {
            if (!is_known[c - 'a']) {
                can_read = false;
                break;
            }
        }
        if (can_read) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}