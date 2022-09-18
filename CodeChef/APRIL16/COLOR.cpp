#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int red = 0, blue = 0, green = 0;
        for (auto c : s) {
            switch (c) {
            case 'R':
                ++red;
                break;
            case 'B':
                ++blue;
                break;
            case 'G':
                ++green;
                break;
            }
        }
        int ans = red + blue + green - max(max(red, blue), green);
        cout << ans << '\n';
    }
    return 0;
}