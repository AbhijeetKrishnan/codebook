#include <iostream>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int cnt[2001] = {0};
		for (int i = 0; i < n; ++i) {
			int tmp;
			scanf("%d", &tmp);
			cnt[tmp + 1000]++;
		}
		long long int ans = 0;
		for (int i = 0; i <= 2000; ++i) {
			for (int j = i + 1; j <= 2000; ++j) {
				if (((i + j )% 2 == 0) && cnt[(i + j) / 2] > 0) {
					ans += (long long int)cnt[i] * cnt[j];
				}
			}
		}
		for (int i = 0; i <= 2000; ++i) {
			ans += ((long long int)cnt[i] * (cnt[i] - 1)) / 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}