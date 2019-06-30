#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(100, 0);
    for (auto &e : a) {
        cin >> e;
        freq[e - 1]++;
    }
    int ans = 0;
    for (int i = 0; i < 100; ++i) {
        ans = max(ans, freq[i]);
    }
    cout << ans;
    return 0;
}