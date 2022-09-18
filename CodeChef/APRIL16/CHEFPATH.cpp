#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
    int t;
    cin >> t;
    while (t--) {
        lli n, m;
        cin >> n >> m;
        if (n > m) {
            swap(n, m);
        }
        if (n == 1 && m != 2) {
            cout << "No\n";
        }
        else if ((n & 1) && (m & 1)) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }
    }
    return 0;
}