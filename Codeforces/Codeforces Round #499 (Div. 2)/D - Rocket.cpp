#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cout << "1\n";
        fflush(stdout);
        int response;
        cin >> response;
        if (response == 0 || response == -2) {
            exit(0);
        }
        else if (response == -1) {
            p[i] = 0;
        }
        else if (response == 1) {
            p[i] = 1;
        }
    }
    int lo = 1, hi = m;
    for (int i = 0; ; i++) {
        int mid = (lo + hi) / 2;
        cout << mid << "\n";
        fflush(stdout);
        int response;
        cin >> response;
        if (p[i % n] == 0) {
            response = -response;
        }
        if (response == 0 || response == -2) {
            exit(0);
        }
        else if (response == -1) {
            hi = mid - 1;
        }
        else if (response == 1) {
            lo = mid + 1;
        }
    }
}