#include <bits/stdc++.h>

using namespace std;

unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u'});

int main() {
    string s;
    cin >> s;
    bool ans = true;
    for (int i = 0; i < s.length(); ++i) {
        if (vowel.count(s[i]) != 1 and s[i] != 'n' and (i + 1 >= s.length() or vowel.count(s[i+1]) != 1)) {
            ans = false;
            break;
        }
    }
    if (ans) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}