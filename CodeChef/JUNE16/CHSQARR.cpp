#include <bits/stdc++.h>

using namespace std;

int v[1001][1001];
int dp[1001][1001];
int max_rows[1001][1001];
int max_cols[1001][1001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; ++i) dp[i][0] = 0;
	for (int j = 0; j <= m; ++j) dp[0][j] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &v[i][j]);
			dp[i+1][j+1] = v[i][j] + dp[i][j+1] + dp[i+1][j] - dp[i][j];
		}
	}
	int queries;
	scanf("%d", &queries);
	while (queries--) {
		int a, b;
		scanf("%d %d", &a, &b);

		deque<int> q;
		for (int i = 0; i < n; ++i) {
			q.clear();
			
			//initialize
			int j;
			for (j = 0; j < b; ++j) {
				while (!q.empty() && v[i][j] >= v[i][q.back()]) {
					//cout << "a: " << i << ' ' << j << ' ' << v[i][j] << '\n';
					q.pop_back();
				}
				q.push_back(j);
			}
			
			//move from left to right
			for ( ; j < m; ++j) {
				max_rows[i][j-b] = v[i][q.front()];
				
				while (!q.empty() && q.front() <= j - b) {
					q.pop_front();
				}
				
				while (!q.empty() && v[i][j] >= v[i][q.back()]) {
					q.pop_back();
				}
				q.push_back(j);
			}
			max_rows[i][j-b] = v[i][q.front()];
		}
		for (int j = 0; j + b - 1 < m; ++j) {
			q.clear();
			
			//initialize
			int i;
			for (i = 0; i < a; ++i) {
				while (!q.empty() && max_rows[i][j] >= max_rows[q.back()][j]) {
					q.pop_back();
				}
				q.push_back(i);
			}
			
			//move from top to bottom
			for ( ; i < n; ++i) {
				max_cols[i-a][j] = max_rows[q.front()][j];
				
				while (!q.empty() && q.front() <= i - a) {
					q.pop_front();
				}
				
				while (!q.empty() && max_rows[i][j] >= max_rows[q.back()][j]) {
					q.pop_back();
				}
				q.push_back(i); 
			}
			max_cols[i-a][j] = max_rows[q.front()][j];
		}
		int ans = INT_MAX, subarray_sum;
		for (int i = 0; i + a - 1 < n; ++i) {
			for (int j = 0; j + b - 1 < m; ++j) {
				subarray_sum = max_cols[i][j] * a * b - (dp[i+a][j+b] - dp[i][j+b] - dp[i+a][j] + dp[i][j]);
				ans = min(ans, subarray_sum);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}