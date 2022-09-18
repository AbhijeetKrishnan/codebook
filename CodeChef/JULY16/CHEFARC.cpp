#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 100000
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k1, k2;
		cin >> n >> m >> k1 >> k2;
		vector<vector<int>> v(n, vector<int>(m)), d1(n, vector<int>(m, INF)), d2(n, vector<int>(m, INF));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> v[i][j];
			}
		}
		
		d1[0][0] = 0;
		deque<pair<int, int>> q1;
		q1.push_back({0, 0});
		while (!q1.empty()) {
			pair<int, int> curr = q1.front();
			q1.pop_front();
			int i = curr.first;
			int j = curr.second;
			for (int x = max(0, i - k1); x <= min(n - 1, i + k1); ++x) {
				for (int y = max(0, j - (k1 - abs(x - i))); y <= min(m - 1, j + (k1 - abs(x - i))); ++y) {
					if (v[x][y] != 1 && d1[x][y] > d1[i][j] + 1) {
						d1[x][y] = d1[i][j] + 1;
						q1.push_back({x, y});
					}
				}
			}
		}
		
		d2[0][m-1] = 0;
		deque<pair<int, int>> q2;
		q2.push_back({0, m - 1});
		while (!q2.empty()) {
			pair<int, int> curr = q2.front();
			q2.pop_front();
			int i = curr.first;
			int j = curr.second;
			for (int x = max(0, i - k2); x <= min(n - 1, i + k2); ++x) {
				for (int y = max(0, j - (k2 - abs(x - i))); y <= min(m - 1, j + (k2 - abs(x - i))); ++y) {
					if (v[x][y] != 1 && d2[x][y] > d2[i][j] + 1) {
						d2[x][y] = d2[i][j] + 1;
						q2.push_back({x, y});
					}
				}
			}
		}
		/*
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << d1[i][j] << ' ';
			}
			cout << '\n';
		}
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << d2[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
		int ans = INF;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ans = min(ans, max(d1[i][j], d2[i][j]));
			}
		}
		if (ans >= INF) ans = -1;
		
		cout << ans << '\n';
	}
	return 0;
}