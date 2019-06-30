#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int main() {
    int n;
    cin >> n;
    int reg_cnt = 0;
    vector<int> freq_open(1000000 + 1, 0);
    vector<int> freq_close(1000000 + 1, 0);
    int open, close;
    bool reg;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        open = 0, close = 0;
        reg = true;
        for (char c: s) {
            if (c == '(')
                open++;
            else {
                close++;
            }
            if (open < close) {
                reg = false;
            }
            if (reg) {
                open -= close;
                close = 0;
            }
        }
        if (open > 0) reg = false;
        //cout << s << " " << reg << " " << open << " " << close << "\n";
        if (reg) {
            reg_cnt++;
        }
        else {
            if (open == 0) {
                freq_close[close]++;
            }
            else if (close == 0) {
                freq_open[open]++;
            }
        }
        
    }
    long long ans = 1LL * reg_cnt * reg_cnt;
    for (int i = 0; i <= 1000000; ++i) {
        ans += 1LL * freq_close[i] * freq_open[i];
    }
    cout << ans;
    return 0;
}