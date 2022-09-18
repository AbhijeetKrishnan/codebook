#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

typedef struct node_tag {
    int d;
    int l;
    int r;
    int mn;
    int mx;
} node;

node t[N];

int traverse(int root) {
    if (t[root].l == -1) {
        return 0;
    }
    int swaps_l = traverse(t[root].l);
    int swaps_r = traverse(t[root].r);
    if (swaps_l == -1 || swaps_r == -1) {
        return -1;
    }
    else if (t[t[root].l].mx < t[t[root].r].mn) {
        t[root].mn = t[t[root].l].mn;
        t[root].mx = t[t[root].r].mx;
        return swaps_l + swaps_r;
    }
    else if (t[t[root].l].mn > t[t[root].r].mx) {
        t[root].mn = t[t[root].r].mn;
        t[root].mx = t[t[root].l].mx;
        return swaps_l + swaps_r + 1;
    }
    else {
        return -1;
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            t[i].l = t[i].r = t[i].d = t[i].mn = t[i].mx = -1;
        }
        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            if (l != -1) {
                l--, r--;
                t[i].l = l;
                t[i].r = r;
                t[i].d = t[i].mn = t[i].mx = -1;
            }
            else {
                t[i].l = -1;
                t[i].r = -1;
                t[i].d =  t[i].mn = t[i].mx = r;
            }
        }

        int ans = traverse(0);
        cout << ans << "\n";
    }
    return 0;
}