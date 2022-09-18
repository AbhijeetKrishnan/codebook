#include <bits/stdc++.h>

using namespace std;

struct tree {
	uint64_t h, r, m;
	tree(): h{0}, r{0}, m{0} {}
	bool operator<(tree& t) {
		return m < t.m;
	}
};

int main() {
	int n;
	uint64_t w, l;
	cin >> n >> w >> l;
	assert(n >= 1 && n <= 100000);
	assert(w >= 1 && w <= 1000000000000000000);
	assert(l >= 1 && l <= 1000000000000000000);
	vector<tree> v(n);
	for (auto &e : v) {
		cin >> e.h >> e.r;
		if (l > e.h)
			e.m = ((l - e.h) % e.r) == 0 ? (l - e.h) / e.r : (l - e.h) / e.r + 1;
		else
			e.m = 0;
		assert(e.h >= 1 && e.h <= 1000000000);
		assert(e.r >= 1 && e.r <= 1000000000);
		assert(e.m >= 0 && e.m <= 1000000000000000000);
		
	}
	sort(v.begin(), v.end());
	/*
	for (auto &e : v) {
		cout << e.h << ' ' << e.r << ' ' << e.m << '\n';
	}
	*/
	uint64_t ans;
	uint64_t curr_h = v[0].h, curr_r = v[0].r, mon = v[0].m;
	if (curr_h + curr_r * mon < w) {
		bool found = false;
		for (int i = 1; i < n; ++i) {
			if (curr_h + v[i].h + (curr_r + v[i].r) * v[i].m < w) {
				curr_h += v[i].h;
				curr_r += v[i].r;
				mon = v[i].m;
			}
			else {
				uint64_t ans1 = ((w - curr_h) % curr_r) == 0 ? (w - curr_h) / curr_r : (w - curr_h) / curr_r + 1;
				uint64_t ans2 = v[i].m;
				ans = min(ans1, ans2);
				found = true;
				break;
			}
		}
		if (!found) {
			ans = ((w - curr_h) % curr_r) == 0 ? (w - curr_h) / curr_r : (w - curr_h) / curr_r + 1;
		}
	}
	else {
		ans = v[0].m;
	}
	cout << ans;
	return 0;
}