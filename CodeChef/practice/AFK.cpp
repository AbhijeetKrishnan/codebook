#include <bits/stdc++.h>

using namespace std;

int T;
long long a, b, c;

long long solve() {
    long long p1 = abs(2 * b - a - c);
    long long p2 = abs(2 * b - c - a);
    long long ans = min(p1, p2);
    long long p3;
    if ((a + c) % 2 == 0) {
        p3 = abs((a + c) / 2 - b);
        ans = min(ans, p3);
    }
    else {
        p3 = abs((a + 1 + c) / 2 - b) + 1;
        ans = min(ans, p3);
        p3 = abs((a - 1 + c) / 2 - b) + 1;
        ans = min(ans, p3);
    }
    return ans;
}

int main() {
    cin >> T;
    for (int test = 0; test < T; ++test) {
        cin >> a >> b >> c;
        cout << solve() << "\n";
    }
    return 0;
}