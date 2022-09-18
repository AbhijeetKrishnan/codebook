#include <bits/stdc++.h>

using namespace std;

bool get(int a, int b, int c, int x, int y) {
    bool possible = false;
    if (x - b >= 0 and x - b <= a and c + a - x + b == y) {
        possible = true;
    }
    return possible;
}

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        bool possible = false;
        if (get(a, b, c, x, y))
            possible = true;
        else if (get(a, b, c, y, x))
            possible = true;
        else if (get(b, a, c, x, y))
            possible = true;
        else if (get(b, a, c, y, x))
            possible = true;
        else if (get(c, a, b, x, y))
            possible = true;
        else if (get(c, a, b, y, x))
            possible = true;
        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}