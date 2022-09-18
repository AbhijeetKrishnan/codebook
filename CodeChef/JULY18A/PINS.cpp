#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n;
        cin >> n;
        cout << "1 1";
        for (int i = 0; i < n - n / 2 - n % 2; ++i) {
            cout << "0";
        }
        cout << "\n";
    }
    return 0;
}