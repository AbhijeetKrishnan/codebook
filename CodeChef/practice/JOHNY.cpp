#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &e : v) {
            cin >> e;
        }
        int k;
        cin >> k;
        int johny = v[k-1];
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            if (v[i] == johny) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}