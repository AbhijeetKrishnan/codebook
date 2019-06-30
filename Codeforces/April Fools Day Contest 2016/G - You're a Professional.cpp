#include <bits/stdc++.h>

using namespace std;

int main() {
    int fr, it, th;
    cin >> fr >> it >> th;
    int ans = 0;
    vector<string> v(fr);
    for (int i = 0; i < fr; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < it; ++i) {
        int count = 0;
        for (int j = 0; j < fr; ++j) {
            if (v[j][i] == 'Y') {
                ++count;
            }
        }
        if (count >= th) {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
