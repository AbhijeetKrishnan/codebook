#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; ++i) {
        vector<bool> seen(n, false);
        int a = i;
        while (not seen[a]) {
            seen[a] = true;
            a = p[a];
        }
        cout << a + 1 << " ";
    }
    return 0;
}