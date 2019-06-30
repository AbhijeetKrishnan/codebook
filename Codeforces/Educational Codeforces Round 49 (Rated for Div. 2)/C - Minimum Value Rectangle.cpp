#include <bits/stdc++.h>

using namespace std;

const int N = 10'000;

bool operator<(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return 1LL * lhs.first * rhs.second < 1LL * rhs.first * lhs.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> poss;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] == a[i+1]) {
                poss.push_back(a[i]);
                i++;
            }
        }
        int m = (int)poss.size();
        pair<int, int> curr = {(poss[m-1] + poss[m-2]) * (poss[m-1] + poss[m-2]), poss[m-1] * poss[m-2]};
        //cout << poss[m-1] << " " << poss[m-2] << " " << curr << "\n";
        pair<int, int> ans = {poss[m-1], poss[m-2]};
        for (int i = m - 2; i - 1 >= 0; i--) {
            pair<int, int> val = {(poss[i] + poss[i-1]) * (poss[i] + poss[i-1]), poss[i] * poss[i-1]};
            //cout << poss[i] << " " << poss[i-1] << " " << val << "\n";
            if (val < curr) {
                curr = val;
                ans = {poss[i], poss[i-1]};
            }
        }
        cout << ans.first << " " << ans.first << " " << ans.second << " " << ans.second << "\n";
    }
    return 0;
}