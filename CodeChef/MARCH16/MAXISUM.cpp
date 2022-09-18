#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (auto &v : a) {
            cin >> v;
        }
        for (auto &v : b) {
            cin >> v;
        }
        int max = abs(b[0]), max_index = 0;
        for (int i = 1; i < n; ++i) {
            if (abs(b[i]) > max) {
                max = abs(b[i]);
                max_index = i;
            }
        }
        if (b[max_index] >= 0) {
            a[max_index] += k;
        }
        else {
            a[max_index] -= k;
        }
        long long int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long long int)a[i] * b[i];
        }
        cout << ans << '\n';
    }
    return 0;
}