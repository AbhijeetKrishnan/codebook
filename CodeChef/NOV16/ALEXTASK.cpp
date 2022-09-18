#include <iostream>
#include <climits>

using namespace std;

int64_t gcd(int64_t a, int64_t b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b); 
}

int64_t lcm(int64_t a, int64_t b) {
	return (a * b) / gcd(a, b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int v[n];
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		int64_t least_lcm = LLONG_MAX;
		for (int i = 0; i + 1 < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				least_lcm = min(least_lcm, lcm(v[i], v[j]));
			}
		}
		cout << least_lcm << '\n';
	}
	return 0;
}