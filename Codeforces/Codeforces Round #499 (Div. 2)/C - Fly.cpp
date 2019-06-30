#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    int a[n], b[n];
    bool one_present = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            one_present = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] == 1) {
            one_present = true;
        }
    }
    if (one_present) {
        cout << "-1";
    }
    else {
        double wt = m;
        for (int i = 0; i < n; ++i) {
            wt += wt / (a[i] - 1);
            wt += wt / (b[i] - 1);
        }
        cout << setprecision(10) << fixed << (wt - m);
    }
    return 0;
}