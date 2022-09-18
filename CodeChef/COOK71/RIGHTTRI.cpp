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
		int64_t H, S;
        cin >> H >> S;
		double x = sqrt(H * H + 4 * S);
		int64_t y_discr = H * H - 4 * S;
		//cout << "y_discr: " << y_discr << '\n';
		if (y_discr < 0) {
			cout << "-1\n";
		}
		else {
			double y = sqrt(y_discr);
			double b = (x + y) / 2;
			double h = (x - y) / 2;
			printf("%.6f %.6f %.6f\n", min(b, h), max(b, h), (double)H);
		}
    }
    return 0;
}