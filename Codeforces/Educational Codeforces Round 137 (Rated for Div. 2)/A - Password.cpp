#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        std::cin >> n;
        int _;
        for (int i = 0; i < n; i++) {
            std::cin >> _;
        }
        int used = 10 - n;
        int ans = 3 * used * (used - 1);
        std::cout << ans << '\n';
    }

    return 0;
}