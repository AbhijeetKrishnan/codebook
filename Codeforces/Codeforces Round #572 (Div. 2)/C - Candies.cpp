#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> segtree(n<<1);
    for (int i = n; i < (n << 1); ++i) {
        cin >> segtree[i].first;
        segtree[i].second = 0;
    }
    for (int i = n - 1; i > 0; i--) {
        if (segtree[i<<1].first + segtree[i<<1|1].first >= 10) {
            segtree[i].second = segtree[i<<1].second + segtree[i<<1|1].second + 1;
        }
        else {
            segtree[i].second = segtree[i<<1].second + segtree[i<<1|1].second;
        }
        segtree[i].first = (segtree[i<<1].first + segtree[i<<1|1].first) % 10;

    }
    int q;
    cin >> q;
    for (int query = 0; query < q; query++) {
        int l, r;
        cin >> l >> r;
        pair<int, int> res = {0, 0};
        for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) {
                res.first += segtree[l].first;
                res.second += segtree[l].second;
                if (res.first >= 10) {
                    res.first %= 10;
                    res.second++;
                }
                l++;
            }
            if (r&1) {
                --r;
                res.first += segtree[r].first;
                res.second += segtree[r].second;
                if (res.first >= 10) {
                    res.first %= 10;
                    res.second++;
                }
            }
        }
        cout << res.second << "\n";
    }
    return 0;
}