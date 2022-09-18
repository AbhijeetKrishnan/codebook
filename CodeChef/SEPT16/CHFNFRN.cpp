/**
 * Author: rashomon
 * Platform: Codechef
 * URL: https://www.codechef.com/SEPT16/problems/CHFNFRN
 * Problem Name: Chef and Friends
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> g(n, vector<bool>(n, true));
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            g[a-1][b-1] = false;
            g[b-1][a-1] = false;
        }
        for (int i = 0; i < n; ++i) {
            g[i][i] = false;
        }
        /*
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << g[i][j] << ' ';
            }
            cout << endl;
        }
        */
        /* Check if complement graph is bipartite */
        bool is_bipartite = true;
        vector<bool> seen(n, false);
        vector<int> colour(n, -1);
        for (int root = 0; root < n; ++root) {
        	if (!seen[root]) {
				deque<int> q;
				q.push_back(root);
				seen[root] = true;
				colour[root] = 0;
				while (!q.empty()) {
				    int curr = q.front();
				    q.pop_front();
				    for (int i = 0; i < n; ++i) {
				        int e;
				        if (g[curr][i]) e = i;
				        else continue;
				        if (!seen[e]) {
				            seen[e] = true;
				            colour[e] = colour[curr] ^ 1;
				            q.push_back(e);
				        }
				        else if (colour[e] == colour[curr]) {
				            is_bipartite = false;
				            q.clear();
				            break;
				        }
				    }
				}
			}
		}
        /*
        for (int i = 0; i < n; ++i) {
            cout << colour[i] << ' ';
        }
        cout << '\n';
        */
        if (is_bipartite) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}