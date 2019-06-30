#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> mod(m, vector<int>());
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mod[a[i] % m].push_back(i);
    }
    int k = n / m;
    vector<int> free;
    for (int i = 0; i < m; ++i) {
        if (mod[i].size() > k) {
            while (mod[i].size() > k) {
                free.push_back(mod[i].back());
                mod[i].pop_back();
            }
        }
    }
    int ans = 0;
    for (int i = m - 2, j = 0; j < m; i = (i - 1 + m) % m, j++) {
        if (mod[i].size() < k) {
            while (mod[i].size() < k) {
                int tmp = ((i - a[free.back()]) % m + m) % m;
                ans += tmp;
                a[free.back()] +=  tmp;
                mod[i].push_back(free.back());
                free.pop_back();
            }
        }
    }
    cout << ans << '\n';
    for (auto e : a) {
        cout << e << ' ';
    }
    return 0;
}