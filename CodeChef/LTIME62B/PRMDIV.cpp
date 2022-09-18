#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
vector<int> psum(N + 1, 0);
vector<int> freq;

int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 2; i <= N; ++i) {
        if (psum[i] != 0)
            continue;
        for (int j = i; j <= N; j += i) {
            psum[j] += i;
        }
    }
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int n;
        cin >> n;
        vector<int> a(n);
        int max_num = -1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            max_num = max(max_num, a[i]);
        }
        freq.assign(max_num + 1, 0);
        for (int a_i: a) {
            freq[a_i]++;
        }
        long long ans = 0;
        for (int i = 2; i <= max_num; ++i) {
            if (freq[i] == 0) continue;
            ans += (1LL * freq[i] * (freq[i]-1));
            for (int j = i + i; j <= max_num; j += i) {
                if (psum[j] % psum[i] == 0) {
                    ans += (1LL * freq[i] * freq[j]);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}