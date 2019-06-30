#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x1(n), y1(n), x2(n), y2(n);
    multiset<int> sx1, sy1, sx2, sy2;
    for (int i = 0; i < n; ++i) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        sx1.insert(x1[i]);
        sy1.insert(y1[i]);
        sx2.insert(x2[i]);
        sy2.insert(y2[i]);
    }
    for (int i = 0; i < n; ++i) {
        sx1.erase(sx1.find(x1[i]));
        sy1.erase(sy1.find(y1[i]));
        sx2.erase(sx2.find(x2[i]));
        sy2.erase(sy2.find(y2[i]));
        int b = *sx1.rbegin(), l = *sy1.rbegin();
        int t = *sx2.begin(), r = *sy2.begin();
        if (b <= t and l <= r) {
            cout << b << " " << l;
            break;
        }
        else {
            sx1.insert(x1[i]);
            sy1.insert(y1[i]);
            sx2.insert(x2[i]);
            sy2.insert(y2[i]);
        }
    }
    return 0;
}