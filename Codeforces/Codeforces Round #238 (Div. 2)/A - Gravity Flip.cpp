#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e : v) {
        cin >> e;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    return 0;
}