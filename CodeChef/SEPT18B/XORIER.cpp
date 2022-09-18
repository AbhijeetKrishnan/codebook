#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'000;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int n;
        cin >> n;
        vector<int> freq(N + 1, 0);
        multiset<int> even, odd;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            freq[tmp]++;
            if (tmp % 2 == 0) {
                even.insert(tmp);
            }
            else {
                odd.insert(tmp);
            }
        }
        long long int ans = 0;
        ans += 1LL * even.size() * (even.size() - 1) / 2;
        ans += 1LL * odd.size() * (odd.size() - 1) / 2;
        long long int subs = 0;
        for (auto e: even) {
            if (e % 4 == 0) {
                subs += even.count(e + 2);
            }
            else if (e % 4 == 1) {
                subs += even.count(e + 2);
            }
            else if (e % 4 == 2) {
                subs += even.count(e - 2);
            }
            else if (e % 4 == 3) {
                subs += even.count(e - 2);
            }
        }
        for (auto e: odd) {
            if (e % 4 == 0) {
                subs += odd.count(e + 2);
            }
            else if (e % 4 == 1) {
                subs += odd.count(e + 2);
            }
            else if (e % 4 == 2) {
                subs += odd.count(e - 2);
            }
            else if (e % 4 == 3) {
                subs += odd.count(e - 2);
            }
        }
        ans -= subs / 2;
        for (int i = 1; i <= N; ++i) {
            ans -= 1LL * freq[i] * (freq[i] - 1) / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}