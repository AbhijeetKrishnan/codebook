#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    a.push_back(0);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    a.push_back(m);
    vector<int> segs;
    for (int i = 1; i <= n + 1; ++i) {
        segs.push_back(a[i] - a[i-1]);
    }
    n = segs.size();
    vector<int> odd(n + 1), even(n + 1);
    odd[0] = even[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            even[i+1] = even[i] + segs[i];
            odd[i+1] = odd[i];
        }
        else {
            even[i+1] = even[i];
            odd[i+1] = odd[i] + segs[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int curr;
        if (i % 2 == 0) {
            //cout << even[i] - even[0] << " " << segs[i] - 1 << " " << odd[n] << " " <<  odd[i+1] << "\n";
            curr = even[i] - even[0] + segs[i] - 1 + odd[n] - odd[i+1];
        }
        else {
            //cout << even[i] - even[0] << " " << segs[i] - 1 << " " << odd[n] << " " <<  odd[i+1] << "\n";
            curr = even[i] - even[0] + segs[i] - 1 + odd[n] - odd[i+1];
        }
        //cout << i << " " << curr << "\n";
        ans = max(ans, curr);
    }
    ans = max(ans, even[n]);
    cout << ans;
    return 0;
}