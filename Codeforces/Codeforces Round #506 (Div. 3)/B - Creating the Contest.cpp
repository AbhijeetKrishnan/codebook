#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e: a) {
        cin >> e;
    }
    int ans = 0, curr = 1;
    for (int i = 1; i < n; ++i) {
        if (2 * a[i-1] < a[i]) {
            ans = max(ans, curr);
            curr = 1;
        }
        else {
            curr++;
        }
    }
    ans = max(ans, curr);
    cout << ans;
    return 0;
}