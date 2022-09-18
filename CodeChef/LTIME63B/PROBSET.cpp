#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n, m;
        cin >> n >> m;
        bool invalid = false, weak = false;
        for (int i = 0; i < n; ++i) {
            string type;
            cin >> type;
            string result;
            cin >> result;
            bool fail_present = false;
            for (char c: result) {
                if (c == '0') {
                    fail_present = true;
                    break;
                }
            }
            if (type == "correct" and fail_present) {
                invalid = true;
            }
            else if (type == "wrong" and not fail_present) {
                weak = true;
            }
        }
        if (invalid) {
            cout << "INVALID\n";
        }
        else if (weak) {
            cout << "WEAK\n";
        }
        else {
            cout << "FINE\n";
        }
    }
    return 0;
}