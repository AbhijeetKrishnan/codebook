#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n;
    int q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        long long int r, c;
        cin >> r >> c;
        long long int ans;
        if ((r + c) % 2 == 0) {
            if (n % 2 == 0) {
                ans = (r - 1) * n / 2 + (c + 1) / 2;
            }
            else {
                if (r % 2 == 1) {
                    ans = (r - 1) * n / 2 + (c + 1) / 2;
                }
                else {
                    ans = (r - 2) * n / 2 + n / 2 + 1 + c / 2;
                }
            }
        }
        else {
            if (n % 2 == 0) {
                ans = (n * n) / 2 + (r - 1) * n / 2 + (c + 1) / 2;
            }
            else {
                if (r % 2 == 1) {
                    ans = (n * n) / 2 + 1 + (r - 1) * n / 2 + c / 2;
                }
                else {
                    ans = (n * n) / 2 + 1 + (r - 2) * n / 2 + n / 2 + (c + 1) / 2;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}