#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }
    if (s.size() < k) {
        cout << "NO";
    }
    else {
        cout << "YES\n";
        int cnt = 0;
        for (auto e: s) {
            for (int i = 0; i < n; ++i) {
                if (e == a[i]) {
                    cout << (i + 1) << " ";
                    cnt++;
                    break;
                }
            }
            if (cnt == k) break;
        }
    }
    return 0;
}