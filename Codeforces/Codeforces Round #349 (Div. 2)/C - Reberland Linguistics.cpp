#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
set<string> suff;
vector<pair<bool, string>> memo(N, make_pair(false, ""));

void get(string s, int n, string prev) {
	//cout << s << ' ' << n << ' ' << prev << ' ' << '\n';
	int len = s.size();
	if (len > 1 && (!memo[n].first || memo[n].second != prev)) {
		if (len > 2) {
			string s3 = s.substr(len - 3);
			if (s3 != prev) {
				suff.insert(s.substr(len - 3));
				get(s.substr(0, len - 3), n - 3, s3);
			}
		}
		string s2 = s.substr(len - 2);
		if (s2 != prev) {
			suff.insert(s.substr(len - 2));
			get(s.substr(0, len - 2), n - 2, s2);
		}
		memo[n].first = true;
		memo[n].second = prev;
	}
}

int main() {
	string s;
	cin >> s;
	if (s.size() > 5)
		get(s.substr(5), s.size(), "");
	cout << suff.size() << '\n';
	for (auto &e : suff) {
		cout << e << '\n';
	}
	return 0;
}