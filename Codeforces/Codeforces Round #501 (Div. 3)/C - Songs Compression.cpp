#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    long long song_sum = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        song_sum += a;
        v[i] = a - b;
    }
    sort(v.begin(), v.end(), greater<int>());
    long long gain = 0;
    int i;
    for (i = 0; i < n and song_sum - gain > m; ++i) {
        //cout << i << " " << v[i] << "\n";
        gain += v[i];
    }
    if (song_sum - gain > m) i = -1;
    cout << i;
    return 0;
}