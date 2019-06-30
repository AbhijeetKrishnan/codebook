#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (i + 1 < n and a[i+1] == b[i] and a[i] == b[i+1]) {
                ans++;
                i++;
            }
            else {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}