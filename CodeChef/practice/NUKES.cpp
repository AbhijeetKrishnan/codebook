#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, n, k;
    cin >> a >> n >> k;
    vector<int> v(k + 1);
    v[0] = a;
    for (int i = 0; i < k; ++i) {
        int new_val = v[i] % (n + 1);
        int forward = v[i] / (n + 1);
        v[i] = new_val;
        v[i + 1] = forward;
        cout << v[i] << ' ';
    }
    return 0;
}