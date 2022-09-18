#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

void push() {
  for (int i = 1; i < n; ++i) {
    t[i<<1] += t[i];
    t[i<<1|1] += t[i];
    t[i] = 0;
  }
}


int main()
{
	int test;
	cin >> test;
	while (test--) {
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			t[n+i] = 0;
		}
		build();
		
		//front
		{
			set<pair<long long int, int>> s;
			int i;
			long long int sum;
			for (i = 1, sum = 0; i < n; sum += a[i], ++i) {
				s.insert({sum, i});
			}
			s.insert({LLONG_MAX, n});
			for (i = 0, sum = 0; i + 1 < n; ++i, sum += a[i]) {
				modify(i + 1, (*s.upper_bound({sum + a[i], n})).second, 1);
			}
		}

		//back
		{
			set<pair<long long int, int>> s;
			int i;
			long long int sum = 0;
			for (i = n - 2, sum = 0; i >= 0; sum += a[i], --i) {
				s.insert({sum, i});
			}
			s.insert({LLONG_MAX, -1});
			for (i = n - 1, sum = 0; i > 0; --i, sum += a[i]) {
				modify((*s.upper_bound({sum + a[i], n})).second + 1, i, 1);
			}
		}
		push();
		for (int i = 0; i < n; ++i) {
			cout << t[n+i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}