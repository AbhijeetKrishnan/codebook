#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto& e : v) {
        cin >> e;
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    int ans_count = 0;
    long long int total = 0;
    int i = 0, j = 1;
    while (i < n) {
        if (v[i] != j && total + j <= m) {
            total += j;
            ans.push_back(j);
            ++ans_count;
            ++j;
        }
        else {
            ++i;
            ++j;
        }
    }
    while (total + j <= m) {
        total += j;
        ans.push_back(j);
        ++ans_count;
        ++j;
    }
    cout << ans_count << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }
    return 0;
}
