#include <bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto &e: v) {
            cin >> e;
        }
        int max_cnt = 0;
        long long rem_money = 0;
        long long curr_sum = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n and curr_sum + v[j] <= k) {
                curr_sum += v[j];
                j++;
            }
            if (max_cnt < j - i or (max_cnt == j - i and rem_money > k - curr_sum)) {
                max_cnt = j - i;
                rem_money = k - curr_sum;
            }
            curr_sum -= v[i];
        }
        cout << max_cnt << " " << rem_money << "\n";
    }
    return 0;
}