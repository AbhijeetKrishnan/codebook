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
		bool has_fail = false;
		bool has_top = false;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int hold;
			cin >> hold;
			if (hold == 2) has_fail = true;
			if (hold == 5) has_top = true;
			sum += hold;
		}
		if (has_fail || !has_top || sum < 4 * n) cout << "No\n";
		else cout << "Yes\n";
    }
    return 0;
}