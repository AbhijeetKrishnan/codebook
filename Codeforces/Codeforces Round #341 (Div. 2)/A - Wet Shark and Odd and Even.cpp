#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    int odd_count = 0, min_odd = INT_MAX;
    long long int ans = 0;
    while (n--) {
        int a;
        cin >> a;
        if (a & 1) {
            ++odd_count;
            if (a < min_odd) {
                min_odd = a;
            }
        }
        ans += a;
    }
    if (odd_count & 1) {
        ans -= min_odd;
    }
    cout << ans;
    return 0;
}
