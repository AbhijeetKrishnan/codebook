#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n, d;
vector<int> v(N);
set<int> seen;

bool possible(int pos) {
    bool ret = true;
    for (int i = 0; i < n; ++i) {
        if (abs(pos - v[i]) < d) {
            ret = false;
            break;
        }
    }
    return ret;
}

int main() {
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (possible(v[i] - d) && seen.count(v[i] - d) != 1) {
            ans++;
            seen.insert(v[i] - d);
        }
        if (possible(v[i] + d) && seen.count(v[i] + d) != 1) {
            ans++;
            seen.insert(v[i] + d);
        }
    }
    cout << ans;
    return 0;
}