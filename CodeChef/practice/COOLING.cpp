#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> pie(n), rack(n);
        for (auto &v : pie) {
            cin >> v;
        }
        for (auto &v : rack) {
            cin >> v;
        }
        sort(pie.begin(), pie.end());
        sort(rack.begin(), rack.end());

        int i = 0, j = 0;
        int ans = 0;
        while (j < n) {
            if (pie[i] <= rack[j]) {
                ++ans;
                ++i;
                ++j;
            }
            else {
                ++j;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}