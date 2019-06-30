#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, B;
    cin >> n >> B;
    int a[n];
    int even[n+1] = {0};
    int odd[n+1] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even[i+1] = even[i] + 1;
            odd[i+1] = odd[i];
        }
        else {
            odd[i+1] = odd[i] + 1;
            even[i+1] = even[i];
        }
    }
    int cut[n-1];
    for (int i = 0; i < n - 1; ++i) {
        cut[i] = INT_MAX;
    }
    for (int i = 0; i < n - 1; ++i) {
        if ((even[i+1] - even[0] == odd[i+1] - odd[0]) && (even[n] - even[i+1] == odd[n] - odd[i+1])) {
            cut[i] = abs(a[i+1] - a[i]);
        }
    }
    sort(cut, cut + (n - 1));
    int total = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if ((long long)total + cut[i] <= B) {
            total += cut[i];
            ++ans;
        }
        else {
            break;
        }
    }
    cout << ans;
    return 0;
}