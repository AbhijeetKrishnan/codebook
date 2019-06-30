#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int times = (n - k) / 2;
    string s;
    cin >> s;
    vector<char> stk;
    for (char c: s) {
        if (c == '(') {
            stk.push_back(c);
        }
        else {
            if (times > 0) {
                stk.pop_back();
                times--;
            }
            else {
                stk.push_back(c);
            }
        }
    }
    for (char c: stk) {
        cout << c;
    }
    return 0;
}