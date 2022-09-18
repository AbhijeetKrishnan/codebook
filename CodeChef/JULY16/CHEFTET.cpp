#include <bits/stdc++.h>

using namespace std;

void calc(vector<int> &a, vector<int> &b, int& ans, int& n) {
	bool is_possible = true;
	for (int i = 1; i < n; ++i) {
		//available elements are max(0, i-1) to min(i+1, n-1)
		int l_lim = max(0, i - 1);
		int r_lim = min(i + 1, n - 1);
		int len = r_lim - l_lim + 1;
		if (len == 2) {
			//take both
			if (a[i] + b[l_lim] + b[l_lim + 1] == a[i-1]) {
				a[i] += b[l_lim] + b[l_lim + 1];
				b[l_lim] = b[l_lim + 1] = 0;
			}
			else {
				is_possible = false;
				break;
			}
		}
		else if (len == 3) {
			//take first
			if (a[i] + b[l_lim] == a[i-1]) {
				a[i] += b[l_lim];
				b[l_lim] = 0;
			}
			//take first and second
			else if (a[i] + b[l_lim] + b[l_lim + 1] == a[i-1]) {
				a[i] += b[l_lim] + b[l_lim + 1];
				b[l_lim] = b[l_lim + 1] = 0;
			}
			//take first and third
			else if (a[i] + b[l_lim] + b[l_lim + 2] == a[i-1]) {
				a[i] += b[l_lim] + b[l_lim + 2];
				b[l_lim] = b[l_lim + 2] = 0;
			}
			//take all 3
			else if (a[i] + b[l_lim] + b[l_lim + 1] + b[l_lim + 2] == a[i-1]) {
				
				a[i] += b[l_lim] + b[l_lim + 1] + b[l_lim + 2];
				b[l_lim] = b[l_lim + 1] = b[l_lim + 2] = 0;
			}
			else {
				is_possible = false;
				break;
			}
		}
	}
	if (is_possible) {
		ans = max(ans, a[0]);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> A(n), B(n);
		for (auto &e : B) {
			cin >> e;
		}
		for (auto &e : A) {
			cin >> e;
		}
		
		if (n == 1) {
			cout << A[0] + B[0] << '\n';
			continue;
		}

		int ans = -1;
		vector<int> a, b;
		
		//Case 1: Take 2
		a = A;
		b = B;
		a[0] += b[0] + b[1];
		b[0] = b[1] = 0;
		calc(a, b, ans, n);
		
		//Case 2: Take second
		a = A;
		b = B;
		a[0] += b[1];
		b[1] = 0;
		calc(a, b, ans, n);
		
		//Case 3: Take first
		a = A;
		b = B;
		a[0] += b[0];
		b[0] = 0;
		calc(a, b, ans, n);
		
		//Case 4: Take none
		a = A;
		b = B;
		calc(a, b, ans, n);
		
		cout << ans << '\n';
	}
	return 0;
}