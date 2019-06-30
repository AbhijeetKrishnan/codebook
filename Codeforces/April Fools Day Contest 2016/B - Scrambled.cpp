#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000000;

int main() {
    int n;
    cin >> n;
    vector<int> M(n), R(n);
    for (auto& v : M) {
        cin >> v;
    }
    for (auto& v : R) {
        cin >> v;
    }
    //cout << "Reached a\n";
    int count = 0;
    for (int i = 0; i < MAX; ++i) {
        bool found = false;
        for (int j = 0; j < n && !found; ++j) {
            if (i % M[j] == R[j]) {
                found = true;
            }
        }
        if (found) {
            ++count;
        }
    }
    //cout << "Reached b\n";
    //cout << count << '\n';
    printf("%.5f", (double)count / MAX);
    return 0;
}
