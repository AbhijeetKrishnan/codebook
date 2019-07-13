#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        prefix_sum[i + 1] = prefix_sum[i] + a; 
    }
    int q;
    cin >> q;
    for (int query = 0; query < q; query++) {
        int l, r;
        cin >> l >> r;
        int ans = (prefix_sum[r] - prefix_sum[l - 1]) / 10;
        cout << ans << "\n";
    }
    return 0;
}