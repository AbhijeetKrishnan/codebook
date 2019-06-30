#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int min_a = INT_MAX, min_i;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < min_a) {
            min_a = a[i];
            min_i = i;
        }
    }
    if (n == 1) {
        cout << "-1\n";
    }
    else if (n == 2 && a[0] == a[1]) {
        cout << "-1\n";
    }
    else {
        cout << "1\n" << min_i + 1;
    }
    return 0;
}