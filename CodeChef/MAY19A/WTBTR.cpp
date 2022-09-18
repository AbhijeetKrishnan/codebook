#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;
        vector<int> plus, minus;
        for (int point = 0; point < n; point++) {
            int x, y;
            cin >> x >> y;
            plus.push_back(y - x);
            minus.push_back(y + x);
        }
        sort(plus.begin(), plus.end());
        sort(minus.begin(), minus.end());
        auto print = [](vector<int>& v) {
            for (auto ele: v) {
                cout << ele << " ";
            }
            cout << "\n";
        };
        //print(plus);
        //print(minus);
        auto get_min_dist = [](vector<int>& v) -> int {
            auto next = v.begin();
            auto prev = next++;
            int min_dist = *next - *prev;
            while (next != v.end()) {
                min_dist = min(*next - *prev, min_dist);
                prev++;
                next++;
            }
            return min_dist;
        };
        int ans = min(get_min_dist(plus), get_min_dist(minus));
        if (ans % 2 == 0) {
            cout << ans / 2 << "\n";
        }
        else {
            cout <<  ans / 2 << ".5\n";
        }
    }
    return 0;
}