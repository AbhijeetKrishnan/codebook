#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;
        int final_winner = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            final_winner ^= stoi(s, nullptr, 2);
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            if (final_winner & (1 << i))
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}