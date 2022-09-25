#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    if (k & 1) {
        cout << (k / 2) * (k / 2 + 1);
    }
    else {
        cout << (k / 2) * (k / 2);
    }
    return 0;
}