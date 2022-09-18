#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> m[26];
        for (int i = 0; i < n; ++i) {
            m[s[i] - 'a'].push_back(i);
        }
        //cout << "Reached a\n";
        vector<long long> total(n);
        long long total_pairs = 0;
        for (int i = 0; i < n; ++i) {
            long long tmp = 0;
            for (int j = 25; j > s[i] - 'a'; j--) {
                tmp += m[j].end() - upper_bound(m[j].begin(), m[j].end(), i);
            }
            for (int j = 0; j < s[i] - 'a'; ++j) {
                tmp += lower_bound(m[j].begin(), m[j].end(), i) - m[j].begin();
            }
            total[i] = tmp;
            total_pairs += tmp;
        }
        total_pairs >>= 1;
        //cout << "Reached b\n";
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            long long tmp = 0;
            vector<long long> gt(26);
            for (int j = 25; j >= 0; j--) {
                gt[j] = tmp;
                tmp += m[j].end() - upper_bound(m[j].begin(), m[j].end(), i);
            }
            //cout << "Reached c\n";
            tmp = 0;
            vector<long long> lt(26);
            for (int j = 0; j < 26; ++j) {
                lt[j] = tmp;
                tmp += lower_bound(m[j].begin(), m[j].end(), i) - m[j].begin();
            }
            //cout << "Reached d\n";
            for (int j = 0; j < 26; ++j) {
                long long Y = total_pairs - total[i] + gt[j] + lt[j];
                int X = abs(s[i] - 'a' - j);
                ans = min(ans, X + Y);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}