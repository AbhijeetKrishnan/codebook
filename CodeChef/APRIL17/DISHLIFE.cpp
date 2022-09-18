#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		vector<unordered_set<int>> ing2island(k, unordered_set<int>()), island2ing(n, unordered_set<int>());
		vector<int> totals(k, 0);
		vector<int> skippable_island(n, -1);
		for (int i = 0; i < n; ++i) {
			int count;
			scanf("%d", &count);
			for (int j = 0; j < count; ++j) {
				int ing;
				scanf("%d", &ing);
				ing2island[ing - 1].insert(i);
				island2ing[i].insert(ing - 1);
				++totals[ing - 1];
			}
		}
		string ans = "all";
		for (int i = 0; i < k; ++i) {
			if (totals[i] == 0) {
				ans = "sad";
				break;
			}
			else if (totals[i] >= 2) {
				//check each island with ingredient i present
				for (auto j : ing2island[i]) {
					//check if island can be skipped
					bool skippable;
					if (skippable_island[j] == 1) {
						skippable = true;
					}
					else if (skippable_island[j] == 0) {
						skippable = false;
					}
					else {
						skippable = true;
						for (auto kk: island2ing[j]) {
							if (totals[kk] == 1) {
									skippable_island[j] = 0;
									skippable = false;
									break;
							}
						}
					}
					if (skippable) {
						skippable_island[j] = 1;
						ans = "some";
						break;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}