#include <bits/stdc++.h>
 
using namespace std;
 
int T;
int n, m;
int q;
int l, r;
long long ret;
 
int main() {
    cin >> T;
    for (int test = 0; test < T; ++test) {
        cin >> n >> m;
        int p[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> p[i][j];
                p[i][j]--;
            }
        }
 
        int pre[n+1][m];
        int inv[n+1][m]; // precalculating all inverses
        for (int i = 0; i < m; ++i) {
            pre[0][i] = inv[0][i] = i; // identity permutation
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                pre[i][j] = p[i-1][pre[i-1][j]];
                inv[i][pre[i][j]] = j;
            }
        }
 
        scanf("%d", &q);
        map<pair<int, int>, long long> store;
        for (int i = 0; i < q; ++i) {
            scanf("%d %d", &l, &r);
            if (store.count({l, r}) == 1) {
                ret = store[{l, r}];
            }
            else {
                ret = 0;
                for (int j = 0; j < m; ++j) {
                    ret += (long long)(j + 1) * (pre[r][inv[l-1][j]] + 1);
                }
                store[{l, r}] = ret;
            }
            printf("%lld\n", ret);
        }
    }
    return 0;
}