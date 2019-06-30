#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ans;
    int cnt = 0;
    for (int u = 1; u <= n && cnt < m; ++u) {
        for (int v = u + 1; v <= n && cnt < m; ++v) {
            if (gcd(u, v) == 1) {
                ++cnt;
                ans.push_back({u, v});
            }
        }
    }
    if (cnt < m || m < n - 1) {
        cout << "Impossible";
    }
    else {
        cout << "Possible\n";
        for (auto e : ans) {
            cout << e.first << " " << e.second << "\n";
        }
    }
    return 0;
}