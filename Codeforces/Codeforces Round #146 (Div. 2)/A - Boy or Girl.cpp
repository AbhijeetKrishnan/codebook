#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int freq[26] = {0};
    for (int i = 0; i < s.length(); ++i) {
        freq[s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            ++ans;
        }
    }
    if (ans & 1) {
        cout << "IGNORE HIM!";
    }
    else {
        cout << "CHAT WITH HER!";
    }
    return 0;
}