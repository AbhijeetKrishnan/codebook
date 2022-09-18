#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto& e : v) {
            cin >> e;
        }
        sort(v.begin(), v.end());
        long long int sum = 0;
        for (int i = k; i <= n - k - 1; ++i) {
            sum += v[i];
        }
        double avg = 1.0 * sum / (n - 2 * k);
        cout << fixed;
        cout << setprecision(10) << avg << '\n';
    }
    return 0;
}