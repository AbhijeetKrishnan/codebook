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
        map<int, int> count;
		for (int i = 0; i < n; ++i) {
			int hold;
			cin >> hold;
			++count[hold];
		}
		/*
		for (auto ele : count) {
			cout << ele.X << ' ' << ele.Y << '\n';
		}
		*/
		auto itr = count.rbegin();
		int max1 = -1;
		while (itr != count.rend()) {
			if (itr -> Y >= 2) {
				max1 = itr -> X;
				count[itr -> X] -= 2;
				break;
			}
			++itr;
		}

		int max2 = -1;
		while (itr != count.rend()) {
			if (itr -> Y >= 2) {
				max2 = itr -> X;
				break;
			}
			++itr;
		}
		int ans;
		if (max1 == -1 || max2 == -1) {
			ans = -1;
		}
		else {
			ans = max1 * max2;
		}
		cout << ans << '\n';
    }
    return 0;
}