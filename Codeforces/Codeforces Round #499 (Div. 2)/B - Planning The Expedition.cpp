#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(101, 0);
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        dp[tmp]++;
    }
    int ans = 0;
    for (int i = 0; i <= 100; ++i) {
        int curr_sum = 0;
        for (int j = 1; j <= 100; ++j) {
            int _div = i;
            if (i == 0) _div = 1;
            curr_sum += dp[j] / _div;
        }
        //cout << i << " " << curr_sum << "\n";
        if (curr_sum >= n) {
            ans = max(ans, i);
        }
        else {
            break;
        }
    }
    cout << ans;
    return 0;
}