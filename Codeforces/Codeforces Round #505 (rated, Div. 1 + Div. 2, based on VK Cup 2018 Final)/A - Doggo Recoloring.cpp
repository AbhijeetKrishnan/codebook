#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    for (char c: s) {
        freq[c - 'a']++;
    }
    bool valid = false;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 1) {
            valid = true;
            break;
        }
    }
    if (n == 1) {
        valid = true;
    }
    if (valid) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}