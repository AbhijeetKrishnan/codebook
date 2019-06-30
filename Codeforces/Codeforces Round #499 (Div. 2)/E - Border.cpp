#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int g = k;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        g = __gcd(g, tmp);
    }
    int cnt = k / g;
    cout << cnt << "\n";
    for (int i = 0; i < k; i += g) {
        cout << i << " ";
    }
    return 0;
}