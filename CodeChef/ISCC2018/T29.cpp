#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> t[4 * N];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = vector<int>(1, a[tl]);
    } else { 
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
              back_inserter(t[v]));
    }
}

int query(int v, int tl, int tr, int l, int r, int x) {
    if (l > r)
        return INT_MAX;
    if (l == tl && r == tr) {
        vector<int>::iterator pos = lower_bound(t[v].begin(), t[v].end(), x);
        if (pos != t[v].end()) {
            if (pos != t[v].begin()) {
                pos--;
                int val1 = *pos;
                pos++;
                int val2 = *pos;
                if (abs(x - val1) < abs(x - val2)) {
                    pos--;
                }
            }
        }
        else {
            pos--;
        }
        return *pos;
    }
    int tm = (tl + tr) / 2;
    int val1 = query(v*2, tl, tm, l, min(r, tm), x);
    int val2 = query(v*2+1, tm+1, tr, max(l, tm+1), r, x);
    if (abs(val1 - x) < abs(val2 - x)) {
        return val1;
    }
    else {
        return val2;
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, Q;
    cin >> n >> Q;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(a, 1, 0, n - 1);
    for (int q = 0; q < Q; q++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        cout << query(1, 0, n - 1, l, r, (int)1e9 - k) << "\n";
    }
    return 0;
}