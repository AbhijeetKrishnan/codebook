#include <bits/stdc++.h>

using namespace std;

int main() {
    int p;
    cin >> p;
    while (p--) {
        int n, m;
        cin >> n >> m;
        string tm(m, '1');
        string ans = "FINE";
        for (int i = 0; i < n; i++){
            string s, t;
            cin >> s >> t;
            bool z = 0; //zeros abesent
            if (tm != t)
                z = 1;//zeros present
            if (s == "correct" && z)
                ans = "INVALID";
            if (s == "wrong" && !z && ans != "INVALID")
                ans = "WEAK";
        }
        cout << ans << '\n';
    }
    return 0;
}