#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 6) {
            cout << "-1\n";
        }
        else if (n % 4 == 0) {
            cout << n << '\n';
            for (int i = 1; i < n - 2; i++) {
                cout << i << ' ' << i + 1 << '\n';
            }
            cout << n - 2 << ' ' << "1\n";
            cout << n - 1 << ' ' << n / 4 << '\n';
            cout << n << ' ' << (3 * n) / 4 << '\n';
            cout << "1\n";
        }
        else if (n % 4 == 1) {
            cout << n << '\n';
            for (int i = 1; i < n - 1; i++) {
                cout << i << ' ' << i + 1 << '\n';
            }
            cout << n - 1 << ' ' << "1\n";
            cout << n << ' ' << 1 + (n - 1) / 4 << '\n';
            cout << "1\n";
        }
        else if (n % 4 == 2) {
            cout << n << '\n';
            for (int i = 1; i < n - 2; i++) {
                cout << i << ' ' << i + 1 << '\n';
            }
            cout << n - 2 << ' ' << "1\n";
            cout << n - 1 << ' ' << 1 + (n - 2) / 4 << '\n';
            cout << n << ' ' << 1 + 3 * (n - 2) / 4 << '\n';
            cout << "1\n";
        }
        else if (n % 4 == 3) {
            cout << n << '\n';
            for (int i = 1; i < n - 3; i++) {
                cout << i << ' ' << i + 1 << '\n';
            }
            cout << n - 3 << ' ' << "1\n";
            cout << n - 2 << ' ' << 1 + (n - 3) / 4 << '\n';
            cout << n - 1 << ' ' << 1 + 2 * (n - 3) / 4 << '\n';
            cout << n << ' ' << 1 + 3 * (n - 3) / 4 << '\n';
            cout << "1\n";
        }
    }
    return 0;
}