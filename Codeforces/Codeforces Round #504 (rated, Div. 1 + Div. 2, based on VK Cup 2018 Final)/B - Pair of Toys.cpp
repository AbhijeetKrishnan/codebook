#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, k;
    cin >> n >> k;
    long long int ans;
    if (k >= 2 * n) {
        ans = 0;
    }
    else {
        if (k <= n) {
            n = k - 1;
        }
        ans = (2 * n - k + 1) / 2;
    }
    cout << ans;
    return 0;
}