#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    set<int> curr;
    curr.insert(a[0]);
    curr.insert(b[0]);
    for (int i = 1; i < n; ++i) {
        set<int> next;
        for (auto g: curr) {
            next.insert(__gcd(g, a[i]));
            next.insert(__gcd(g, b[i]));
        }
        curr = next;
    }
    int wcd = -1;
    for (auto e: curr) {
        if (e != 1) {
            wcd = e;
            break;
        }
    }
    cout << wcd;
    return 0;
}