#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int n, x, s;
        cin >> n >> x >> s;
        vector<int> v(n, 0);
        v[x - 1] = 1;
        for (int swaps = 0; swaps < s; ++swaps) {
            int a, b;
            cin >> a >> b;
            swap(v[a-1], v[b-1]);
        }
        for (int i = 0; i < n; ++i) {
            if (v[i] == 1) {
                cout << i + 1 << "\n";
            }
        }
    }
    return 0;
}