#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e: v) {
        cin >> e;
    }
    sort(v.rbegin(), v.rend());
    if (v[0] >= v[1] + v[2]) {
        cout << "NO";
    }
    else {
        cout << "YES\n";
        deque<int> d;
        d.push_back(v[0]);
        for (int i = 1, back = 1; i < n; i++, back ^= 1) {
            if (back) {
                d.push_back(v[i]);
            }
            else {
                d.push_front(v[i]);
            }
        }
        for (auto e: d) {
            cout << e << " ";
        }
    }
    return 0;
}