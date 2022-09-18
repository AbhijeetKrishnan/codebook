#include <bits/stdc++.h>

using namespace std;
const int MAX = 2814000 + 1;

vector<int> triangles(MAX, 0);

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> paper(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> horizontal(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> vertical(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> diag_bslash(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> diag_fslash(n + 1, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int val;
            cin >> val;
            paper[i][j] = horizontal[i][j] = vertical[i][j] = diag_bslash[i][j] = diag_fslash[i][j] = val;
        }
    }

    /* Precomputing tables */
    // horizontal
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            horizontal[i][j] += horizontal[i][j - 1];
        }
    }
    // vertical
    for (int j = 1; j <= m; ++j) {
        for (int i = 2; i <= n; ++i) {
            vertical[i][j] += vertical[i - 1][j];
        }
    }
    // bslash along n
    for (int i = n; i > 1; --i) {
        for (int p = i, q = 2; p <= n && q <= m; ++p, ++q) {
            diag_bslash[p][q] += diag_bslash[p - 1][q - 1];
        }
    }
    // bslash along m
    for (int j = 3; j <= m; ++j) {
        for (int p = 2, q = j; p <= n && q <= m; ++p, ++q) {
            diag_bslash[p][q] += diag_bslash[p - 1][q - 1];
        }
    }
    // fslash along m
    for (int j = 1; j < m; ++j) {
        for (int p = 2, q = j; p <= n && q >= 1; ++p, --q) {
            diag_fslash[p][q] += diag_fslash[p - 1][q + 1];
        }
    }
    // fslash along n
    for (int i = 3; i <= n; ++i) {
        for (int p = i, q = m - 1; p <= n && q >= 1; ++p, --q) {
            diag_fslash[p][q] += diag_fslash[p - 1][q + 1];
        }
    }

    /* Calculating capacities for all triangles */
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int val = paper[i][j];
            //TL
            for (int p = j - 1, q = i - 1; p >= 1 && q >= 1; --p, --q) {
                val += diag_fslash[i][p] - diag_fslash[q - 1][j + 1];
                ++triangles[val];
            }
            val = paper[i][j];
            //T
            for (int p = j + 1, q = j - 1, r = i - 1; p <= m && q >= 1 && r >= 1; ++p, --q, --r) {
                val += horizontal[r][p] - horizontal[r][q - 1];
                ++triangles[val];
            }
            val = paper[i][j];
            //TR
            for (int p = j + 1, q = i - 1; p <= m && q >= 1; ++p, --q) {
                val += diag_bslash[i][p] - diag_bslash[q - 1][j - 1];
                ++triangles[val];
            }
            val = paper[i][j];
            //R
            for (int p = i + 1, q = i - 1, r = j + 1; p <= n && q >= 1 && r <= m; ++p, --q, ++r) {
                val += vertical[p][r] - vertical[q - 1][r];
                ++triangles[val];
            }
            val = paper[i][j];
            //BR
            for (int p = i + 1, q = j + 1; p <= n && q <= m; ++p, ++q) {
                val += diag_fslash[p][j] - diag_fslash[i - 1][q + 1];
                ++triangles[val];
            }
            val = paper[i][j];
            //B
            for (int p = j + 1, q = j - 1, r = i + 1; p <= m && q >= 1 && r <= n; ++p, --q, ++r) {
                val += horizontal[r][p] - horizontal[r][q - 1];
                ++triangles[val];
            }
            val = paper[i][j];
            //BL
            for (int p = i + 1, q = j - 1; p <= n && q >= 1; ++p, --q) {
                val += diag_bslash[p][j] - diag_bslash[i - 1][q - 1];
                ++triangles[val];
            }
            val = paper[i][j];
            //L
            for (int p = i + 1, q = i - 1, r = j - 1; p <= n && q >= 1 && r >= 1; ++p, --q, --r) {
                val += vertical[p][r] - vertical[q - 1][r];
                ++triangles[val];
            }
        }
    }
    /*
    for (int i = 0; i < MAX; ++i) {
        if (triangles[i] != 0) {
            cout << i << " " << triangles[i] << "\n";
        }
    }
    */
    /* Storing queries for offline processing */
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first;
        queries[i].second = i;
    }
    sort(queries.begin(), queries.end());

    /* Calculating ans vector */
    vector<int> ans(q);
    int total = 0, count = 0;
    int t_ptr = 1, q_ptr = 0;
    while (t_ptr < MAX && q_ptr < q) {
        while (t_ptr < MAX && total <= queries[q_ptr].first) {
            /*
            if (triangles[t_ptr] != 0)
                cout << t_ptr << " " << count << '\n';
            */
            total += triangles[t_ptr] * t_ptr;
            count += triangles[t_ptr];
            ++t_ptr;
        }
        if (total > queries[q_ptr].first) {
            //cout << t_ptr << " " << total << '\n';
            ans[queries[q_ptr].second] = count - triangles[t_ptr - 1] + (queries[q_ptr].first - (total - triangles[t_ptr - 1] * (t_ptr - 1))) / (t_ptr - 1);
            ++q_ptr;
        }
    }
    while (q_ptr < q) {
        ans[queries[q_ptr].second] = count;
        ++q_ptr;
    }
    for (auto ele : ans) {
        cout << ele << '\n';
    }
    return 0;
}