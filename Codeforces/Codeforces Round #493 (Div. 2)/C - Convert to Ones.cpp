#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int zero_runs = (s[0] == '0') ? 1 : 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == '1' && s[i+1] == '0') {
            zero_runs++;
        }
    }
    //cout << zero_runs << "\n";
    long long ans;
    if (zero_runs == 0) {
        ans = 0;
    }
    else if (x < y) {
        ans = (long long)(zero_runs - 1) * x + y;
    }
    else {
        ans = (long long)zero_runs * y;
    }
    cout << ans << "\n";
}