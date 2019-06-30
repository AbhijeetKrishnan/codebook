#include <bits/stdc++.h>

using namespace std;

int log2(int n) {
    int ret = 0;
    while (n > 1) {
        n >>= 1;
        ret++;
    }
    return ret;
}

int main() {
    int n, q;
    cin >> n >> q;
    int _;
    vector<int> freq(32, 0);
    for (int i = 0; i < n; ++i) {
        cin >> _;
        freq[log2(_)]++;
    }
    cout << "\n";
    while (q--) {
        long long b;
        cin >> b;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            ans += min(b / (1 << i), (long long)freq[i]);
            b -= (1 << i) * min(b / (1 << i), (long long)freq[i]);
        }
        if (b == 0) {
            cout << ans << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    return 0;
}