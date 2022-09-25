#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) {
            //cout << i << "\n";
            ++ans;
            if (i + 1 < n)
                a[i] = a[i+1] + 1;
        }
    }
    cout << ans;
    return 0;
}