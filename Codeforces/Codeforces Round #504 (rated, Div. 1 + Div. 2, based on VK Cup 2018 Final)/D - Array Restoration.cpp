#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<vector<int>> v(q + 1, vector<int>());
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    /*
    for (int i = 0; i <= q; ++i) {
        cout << i << ": ";
        for (auto e: v[i]) {
            cout << e << " ";
        }
        cout << "\n";
    }
    */
    multiset<int> s;
    bool valid = true;
    for (int i = q; i > 0 and valid; i--) {
        if ((int)v[i].size() > 0) {
            for (auto e: v[i]) {
                /*
                for (auto f: s) {
                    cout << f << " ";
                }
                cout << "\n";
                */
                int dist = distance(s.begin(), s.lower_bound(e));
                //cout << i << " " << dist << "\n";
                if (dist % 2 != 0) {
                    valid = false;
                    break;
                }
            }
            s.insert(v[i].front());
            s.insert(v[i].back());
        }
    }
    if (not valid) {
        cout << "NO";
    }
    else {
        cout << "YES\n";
        for (int i = 1; i < n; ++i) {
            if (a[i] == 0 and a[i-1] != 0) {
                a[i] = a[i-1];
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] == 0 and a[i+1] != 0) {
                a[i] = a[i+1];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                a[i] = q;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
    }
    return 0;
}