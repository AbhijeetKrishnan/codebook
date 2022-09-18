#include <bits/stdc++.h>

using namespace std;
vector<uint64_t> sums;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto &e : v) {
		cin >> e;
	}
	for (int i = 0; i < n; ++i) {
		uint64_t sum = 0;
		for (int j = i; j < n; ++j) {
			sum += v[j];
			sums.push_back(sum);
		}
	}
	sort(sums.begin(), sums.end(), cmp);
	for (int i = 0; i < k; ++i) {
		cout << sums[i] << ' ';
	}
	return 0;
}