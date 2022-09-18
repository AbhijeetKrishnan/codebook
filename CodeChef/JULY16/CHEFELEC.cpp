#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

typedef unordered_map<int, vector<int>> graph;
typedef unordered_map<int, vector<pair<int, int>>> weighted_graph;

const int M = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
		cin >> s;
		vector<int> x(n);
		for (auto &e : x) {
			cin >> e;
		}
		vector<int> ones;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				ones.push_back(i);
			}
		}
		int ans = x[ones[0]] - x[0] + x[n-1] - x[ones[ones.size() - 1]];
		for (int i = 1; i < ones.size(); ++i) {
			int min_val = INT_MAX;
			for (int j = ones[i-1]; j < ones[i]; ++j) {
				min_val = min(min_val, x[j] - x[ones[i-1]] + x[ones[i]] - x[j+1]);
			}
			ans += min_val;
		}
		cout << ans << '\n';
    }
    return 0;
}