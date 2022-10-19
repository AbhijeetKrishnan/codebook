#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        std::cin >> n;
        std::cout << "1 ";
        for (int i = n; i > 1; i--) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}