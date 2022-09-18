#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

typedef unordered_map<int, vector<int>> graph;
typedef unordered_map<int, vector<pair<int, int>>> weighted_graph;

const int M = 786433;

int main() {
    int n;
	cin >> n;
	vector<int> a(n + 1);
	for (auto &e : a) {
		cin >> e;
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		int64_t sum = 0;
		for (int i = n; i >= 0; --i) {
			sum = (sum * x) % M;
			sum = (sum + a[i]) % M;
		}
		cout << sum << '\n';
	}
    return 0;
}