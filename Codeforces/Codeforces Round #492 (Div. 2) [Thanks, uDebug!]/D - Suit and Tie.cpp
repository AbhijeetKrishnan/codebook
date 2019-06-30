#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> v[i];
    }
    int ans = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        if (v[i] != v[i + 1]) {
            int j = i + 1;
            while (v[j] != v[i]) j++;
            while (j - 1 > i) {
                ans++;
                swap(v[j], v[j-1]);
                j--;
            }
        }
    }
    cout << ans;
    return 0;
}