#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            int ele;
            cin >> ele;
            k ^= ele;
        }
        if (k == 0) {
            cout << "First\n";
        }
        else {
            if (n & 1) {
                cout << "Second\n";
            }
            else {
                cout << "First\n";
            }
        }
    }
    return 0;
}