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
    cout << v[(n + 1) >> 1];
    return 0;
}