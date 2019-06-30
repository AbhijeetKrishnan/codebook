#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    bool ans = true;
    int curr = max(v[0].first, v[0].second);
    for (int i = 1; i < n; ++i) {
        if (max(v[i].first, v[i].second) > curr and min(v[i].first, v[i].second) > curr) {
            ans = false;
            break;
        }
        else if (max(v[i].first, v[i].second) > curr) {
            curr = min(v[i].first, v[i].second);
        }
        else {
            curr = max(v[i].first, v[i].second);
        }
    }
    if (ans) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}