#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        std::cin >> n;
        auto lid = std::vector<int>(n);
        for (auto &lid_i : lid) {
            char c;
            std::cin >> c;
            lid_i = c - '0';
        }
        auto a = std::vector<int>(n);
        for (auto &a_i : a) {
            std::cin >> a_i;
        }

        auto max_saved = std::vector<std::vector<int>>(n, std::vector<int>(2));
        max_saved[0][0] = 0;
        max_saved[0][1] = lid[0] ? a[0] : 0;

        for (int i = 1; i < n; i++) {
            if (!lid[i]) {
                max_saved[i][1] = 0;
                max_saved[i][0] = std::max(max_saved[i - 1][0], max_saved[i - 1][1]);
            } else {
                max_saved[i][0] = max_saved[i - 1][0] + a[i - 1]; // swap lids
                max_saved[i][1] = std::max(max_saved[i - 1][0], max_saved[i - 1][1]) + a[i]; // don't swap lids
            }
        }
        int ans = std::max(max_saved[n - 1][0], max_saved[n - 1][1]);
        std::cout << ans << '\n';
    }

    return 0;
}