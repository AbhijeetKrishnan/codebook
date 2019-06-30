#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    bool possible = false;
    for (int i = 1; i + 1 < n; ++i) {
        set<char> st;
        if (s[i] != '.') st.insert(s[i]);
        if (s[i-1] != '.') st.insert(s[i-1]);
        if (s[i+1] != '.') st.insert(s[i+1]);
        if (st.size() == 3) {
            possible = true;
            break;
        }
    }
    if (possible) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}