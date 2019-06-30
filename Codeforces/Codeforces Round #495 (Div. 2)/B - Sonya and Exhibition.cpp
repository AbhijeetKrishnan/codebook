#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int n, m;
int tmp;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> tmp >> tmp;
    }
    int curr = 1;
    for (int i = 0; i < n; ++i) {
        cout << (curr ^ 1);
        curr ^= 1;
    }
    return 0;
}