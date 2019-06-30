#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }
    int ans = n;
    auto i = m.begin();
    auto j = i++;
    while (i != m.end()) {
        if ((*i).first <= (*j).first + k) {
            ans -= (*j).second;
        }
        i++;
        j++;
    }
    cout << ans;
    return 0;
}