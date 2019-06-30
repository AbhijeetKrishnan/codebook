#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {100, 20, 10, 5, 1};
    int n;
    cin >> n;
    int ans = 0;
    for (int i: v) {
        ans += n / i;
        n %= i;
    }
    cout << ans;
    return 0;
}