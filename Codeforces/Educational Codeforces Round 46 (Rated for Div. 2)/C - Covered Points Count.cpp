#include <bits/stdc++.h>

using namespace std;

struct data_t {
    long long p;
    int s;
    int e;
    data_t(long long pp, int ss, int ee): p {pp}, s {ss}, e {ee} {}
};

int main() {
    int n;
    cin >> n;
    assert(1 <= n and n <= 2 * 1e5);
    vector<pair<long long, int>> v;
    vector<long long> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        long long l, r;
        cin >> l >> r;
        assert(0 <= l and l <= 1e18);
        assert(0 <= r and r <= 1e18);
        v.push_back({l, -1});
        v.push_back({r, 1});
    }
    sort(v.begin(), v.end());
    vector<data_t> dv;
    for (int i = 0; i < 2 * n; ) {
        int s = 0, e = 0;
        if (v[i].second == -1) {
            s++;
        }
        else {
            e++;
        }
        int j;
        for (j = i + 1; j < 2 * n and v[j].first == v[j-1].first; j++) {
            if (v[j].second == -1) {
                s++;
            }
            else {
                e++;
            }
        }
        dv.push_back(data_t(v[i].first, s, e));
        i = j;
    }
    int lvl = 0;
    lvl += dv[0].s;
    assert(0 <= lvl and lvl <= n);
    cnt[lvl]++;
    lvl -= dv[0].e;
    int i;
    for (i = 1; i < (int)dv.size(); ++i) {
        assert(0 <= lvl and lvl <= n);
        cnt[lvl] += dv[i].p - dv[i-1].p - 1;
        lvl += dv[i].s;
        assert(0 <= lvl and lvl <= n);
        cnt[lvl]++;
        lvl -= dv[i].e;
    }
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << " ";
    }
    return 0;
}