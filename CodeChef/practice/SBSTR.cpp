#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        int n = s.size();
        int a[26][n + 1];
        for (int i = 0; i < 26; ++i) {
            a[i][0] = 0;
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                a[i][j] = a[i][j-1] + (i == s[j-1] - 'a');
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + k; j < n + 1; ++j) {
                bool valid = true;
                int comm = -1;
                int distinct = 0;
                for (int l = 0; l < 26; ++l) {
                    int freq = a[l][j] - a[l][i];
                    if (freq > 0) {
                        distinct++;
                        if (comm == -1) {
                            comm = freq;
                        }
                        else if (comm != freq) {
                            valid = false;
                            break;
                        }
                    }
                }
                if (distinct < k) {
                    valid = false;
                }
                if (valid) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}