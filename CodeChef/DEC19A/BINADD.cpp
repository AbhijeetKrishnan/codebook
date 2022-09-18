#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_tests;
    cin >> num_tests;
    for (int test = 0; test < num_tests; test++) {
        string a, b;
        cin >> a;
        cin >> b;
        bool contains_one = false;
        for (char c: b) {
            if (c == '1') {
                contains_one = true;
                break;
            }
        }
        if (not contains_one) {
            cout << "0\n";
            continue;
        }
        int max_run = 1;
        int curr_run = 0;
        bool in_run = false;
        int max_len = max(a.size(), b.size());
        a.insert(a.begin(), max_len - a.size() + 1, '0');
        b.insert(b.begin(), max_len - b.size() + 1, '0');
        for (int i = a.size() - 1; i >= 0; i--) {
            if (in_run and ((a[i] == '0' and b[i] == '1') or (a[i] == '1' and b[i] == '0'))) {
                curr_run++;
            }
            else {
                max_run = max(max_run, curr_run + 1);
                in_run = false;
            }
            if ((a[i] == '1' and b[i] == '1')) {
                in_run = true;
                curr_run = 1;
            }
        }
        cout << max_run << "\n";
    }
    return 0;
}