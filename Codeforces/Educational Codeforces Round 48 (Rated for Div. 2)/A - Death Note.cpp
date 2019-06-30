#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &e: a) {
        cin >> e;
    }
    int ans = 0;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        cout << (curr + a[i]) / m << " ";
        curr = (curr + a[i]) % m;
    }
    return 0;
}