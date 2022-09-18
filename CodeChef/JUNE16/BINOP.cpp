#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a;
		cin >> b;
		int n01 = 0, n10 = 0;
		bool has_one = false, has_zero = false;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] == '0') has_zero = true;
			if (a[i] == '1') has_one = true;
			if (a[i] == '0' && b[i] == '1') {
				++n01;
			}
			else if (a[i] == '1' && b[i] == '0') {
				++n10;
			}
		}
		int ans;
		if (n01 >= n10 && has_one) {
			ans = min(n01, n10) + n01 - n10;
			cout << "Lucky Chef\n" << ans << '\n';
		}
		else if (n10 >= n01 && has_zero) {
			ans = min(n01, n10) + n10 - n01;
			cout << "Lucky Chef\n" << ans << '\n';
		}
		else {
			cout << "Unlucky Chef\n";
		}
	}
	return 0;
}