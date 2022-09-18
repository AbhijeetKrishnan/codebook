#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int u, v, n;
        cin >> n >> u >> v;
        int a = 0;
        if (v < u) {
            swap(u, v);
        }
        list<int> num;
        while (u != v) {
            if (u > v) {
                u >>= 1;
            }
            else {
                num.push_front(v & 1);
                ++a;
                v >>= 1;
            }
        }
        int b = 0;
        for (auto i : num) {
            b = (b << 1) + i;
        }
        int ans = (n - b) / (1<<a);
        cout << ans << '\n';
    }
    return 0;
}