#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> items(k), index(k);
    for (int i = 0; i < k; ++i) {
        int hold;
        cin >> hold;
        items[i] = hold - 1;
        index[items[i]] = i;
    }
    int ans = 0;
    while (n--) {
        for (int i = 1; i <= m; ++i) {
            int want;
            cin >> want;
            want -= 1;
            ans += index[want] + 1;
            for (int i = index[want] - 1; i >= 0; --i) {
                index[items[i]] = i + 1;
                items[i + 1] = items[i];
            }
            index[want] = 0;
            items[0] = want;
        }
    }
    cout << ans;
    return 0;
}
