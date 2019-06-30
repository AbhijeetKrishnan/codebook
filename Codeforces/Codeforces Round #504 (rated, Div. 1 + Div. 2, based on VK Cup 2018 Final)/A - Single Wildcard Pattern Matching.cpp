#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    bool valid = true;
    int i = 0, j = 0;
    while (i < n and j < m and s[i] == t[j]) {
        i++;
        j++;
    }
    if ((i >= n and j < m) or (i < n and s[i] != '*')) valid = false;
    else if (i >= n and j >= m) valid = true;
    else {
        int star = i;
        i = n - 1, j = m - 1;
        while (i >= 0 and i < n and j >= 0 and j < m and s[i] == t[j]) {
            i--;
            j--;
        }
        if (s[i] != '*' or j < star - 1) {
            valid = false;
        }
    }
    if (valid) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}