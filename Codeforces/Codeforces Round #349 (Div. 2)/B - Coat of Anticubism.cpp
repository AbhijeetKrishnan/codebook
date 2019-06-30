#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	uint64_t sum = 0;
	int max_len = 0;
	for (int i = 0; i < n; ++i) {
		int hold;
		cin >> hold;
		sum += hold;
		max_len = max(hold, max_len);
	}
	uint64_t ans = (max_len<<1) - sum + 1;
	cout << ans;
	return 0;
}