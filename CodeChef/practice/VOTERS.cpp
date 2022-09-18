#include <bits/stdc++.h>

using namespace std;

int main() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	map<int, int> freq;
	for (int i = 0; i < (n1 + n2 + n3); ++i) {
		int hold;
		cin >> hold;
		++freq[hold];
	}
	int count = 0;
	for (auto i : freq) {
		if (i.second > 1) ++count;
	}
	cout << count << '\n';
	for (auto i : freq) {
		if (i.second > 1) cout << i.first << '\n';
	}
	return 0;
}