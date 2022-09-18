#include <bits/stdc++.h>

using namespace std;

struct movie {
    int ind, l, r;
    movie(): ind{0}, l{0}, r{0} {}
    movie(int ii, int ll, int rr): ind{ii}, l{ll}, r{rr} {}
    bool operator<(const movie &m) {
        if (l * r < m.l * m.r) {
            return false;
        }
        else if ((l * r == m.l * m.r) && r < m.r) {
            return false;
        }
        else if ((l * r == m.l * m.r) && (r == m.r) && ind > m.ind) {
            return false;
        }
        else {
            return true;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<movie> v(n);
        for (int i = 1; i <= n; ++i) {
            cin >> v[i-1].l;
            v[i-1].ind = i;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> v[i-1].r;
        }
        sort(v.begin(), v.end());
        /*
        for (auto e : v) {
            cout << e.ind << '\n';
        }
        */
        cout << (v.begin() -> ind) << '\n';
    }
    return 0;
}