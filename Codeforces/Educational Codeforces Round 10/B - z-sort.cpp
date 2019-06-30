#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), ans(n);
    for (auto& e : a) {
        cin >> e;
    }
    sort(a.begin(), a.end());
    for (int i = 0, j = n - 1, k = 0; i <= j; ++i, --j) {
        if (i == j) {
            ans[k++] = a[i];
        }
        else {
            ans[k++] = a[i];
            ans[k++] = a[j];
        }
    }
    for (auto e : ans) {
        cout << e << ' ';
    }
    return 0;
}
