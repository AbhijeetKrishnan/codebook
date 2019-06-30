#include <bits/stdc++.h>

using namespace std;
const double PI = 3.14159265359;

int main() {
	int d, h, v, e;
	cin >> d >> h >> v >> e;
	double r1 = PI * (d * d) / 4 * e;
	if (r1 >= v) {
		cout << "NO";
	}
	else {
		double r = v - r1;
		double ans = (PI * d * d / 4 * h) / r;
		cout << "YES\n";
		cout << setprecision(20) << ans;
	}
	return 0;
}