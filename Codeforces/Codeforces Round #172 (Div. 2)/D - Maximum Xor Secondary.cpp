#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	stack<int> s;
	for (int i = 0, v; i < n; ++i) {
		cin >> v;
		for ( ; !s.empty(); s.pop()) {
			int x = s.top();
			ans = max(ans, v ^ x);
			if (x > v) {
				break;
			}
		}
		s.push(v);
	}
	cout << ans << endl;
	return 0;
}