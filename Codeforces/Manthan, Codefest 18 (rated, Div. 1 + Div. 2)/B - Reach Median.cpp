#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto &e: a) {
        cin >> e;
    }
    sort(a.begin(), a.end());
    long long int ans = 0;
    if (a[n/2] < s) {
        for (int i = n / 2; i < n and a[i] < s; i++) {
            ans += s - a[i];
        }
    }
    else if (a[n/2] > s) {
        for (int i = n / 2; i >= 0 and a[i] > s; i--) {
            ans += a[i] - s;
        }
    }
    cout << ans;
    return 0;
}