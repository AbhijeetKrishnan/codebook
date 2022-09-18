#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &ele : v) {
            cin >> ele;
        }
        vector<int> a(n);
        a[n - 1] = 1;
        for (int i = n - 2; i > -1; --i) {
            if (v[i] <= 0 && v[i+1] >= 0) {
                a[i] = a[i+1] + 1;
            }
            else if (v[i] >= 0 && v[i+1] <= 0) {
                a[i] = a[i+1] + 1;
            }
            else {
                a[i] = 1;
            }
        }
        for (auto ele : a) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}