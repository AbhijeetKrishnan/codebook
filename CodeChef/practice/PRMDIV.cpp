#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
vector<int> psum(N + 1, 0);
vector<int> good[N + 1];
vector<int> freq;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    for (int i = 2; i <= N; ++i) {
        if (psum[i] != 0)
            continue;
        for (int j = i; j <= N; j += i) {
            psum[j] += i;
        }
    }
    for (int i = 2; i <= N; ++i) {
        for (int j = i + i; j <= N; j += i) {
            if (psum[j] % psum[i] == 0) {
                good[i].push_back(j);
            }
        }
    }
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n;
        cin >> n;
        freq.assign(N + 1, 0);
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            freq[tmp]++;
        }
        long long ans = 0;
        for (int i = 2; i <= N; ++i) {
            if (freq[i] == 0) continue;
            ans += 1LL * freq[i] * (freq[i] - 1);
            for (int j: good[i]) {
                ans += 1LL * freq[i] * freq[j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}