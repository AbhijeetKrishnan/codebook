#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	int mx = 0, mn = INT_MAX;
	for (int i = 0; i < n; ++i) {
		int hold;
		cin >> hold;
		mx = max(mx, hold);
		mn = min(mn, hold);
	}
	for (int i = 0; i < q; ++i) {
		int hold;
		cin >> hold;
		if (hold <= mx && hold >= mn) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}