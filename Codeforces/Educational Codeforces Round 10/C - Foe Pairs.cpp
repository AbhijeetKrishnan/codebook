#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n), inv(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        inv[a[i]] = i;
    }
    vector<int> rightmost_foe(n, -1); // ith index stores index of rightmost foe for ith element
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        if (inv[a] > inv[b]) {
            swap(a, b);
        }
        rightmost_foe[inv[b]] = max(rightmost_foe[inv[b]], inv[a]);
    }
    long long int ans = 0;
    int i = 0, j = 0;
    while (i < n) {
        if (rightmost_foe[i] >= j) {
            int size = i - j;
            ans += 1LL * size * (size + 1) / 2;
            j = rightmost_foe[i] + 1;
            size = i - j;
            ans -= 1LL * size * (size + 1) / 2;
        }
        ++i;
    }
    int size = i - j;
    ans += 1LL * size * (size + 1) / 2;
    printf("%I64d", ans);
    return 0;
}
