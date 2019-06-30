#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    map<int, int> freq;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(a[i]);
        if (freq.count(a[i]) == 0) {
            freq[a[i]] = 1;
        }
        else {
            freq[a[i]]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < 31 and not found; ++j) {
            //cout << (1<<(j+1) - a[i]) << "\n";
            if (s.find((1<<(j+1)) - a[i]) != s.end()) {
                //cout << (a[i] << 1) << " " << (1 << (j + 1)) << "\n";
                if ((a[i] << 1) == (1 << (j + 1))) {
                    //cout << i << " " << (1<<(j+1)) << " " << freq[a[i]] << "\n";
                    if (freq[a[i]] > 1) {
                        //cout << i << " " << (1<<(j+1)) << "\n";
                        found = true;
                    }
                }
                else {
                    //cout << i << " " << (1<<(j+1)) << "\n";
                    found = true;
                }
            }
        }
        if (not found) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}