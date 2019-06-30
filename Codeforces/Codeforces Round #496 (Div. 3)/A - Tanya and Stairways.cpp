#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int steps = 0;
    int stairs = 0;
    int a[n];
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1 && i != 0) {
            steps++;
            ans.push_back(a[i-1]);
        }
    }
    steps++;
    ans.push_back(a[n-1]);
    cout << steps << "\n";
    for (auto e : ans) {
        cout << e << " ";
    }
    return 0;
}