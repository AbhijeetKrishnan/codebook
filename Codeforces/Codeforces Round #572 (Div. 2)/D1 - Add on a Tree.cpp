#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> degree(n, 0);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        degree[u - 1]++;
        degree[v - 1]++;
    }
    bool possible = true;
    for (int i: degree) {
        if (i == 2) {
            possible = false;
            break;
        }
    }
    if (possible) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}