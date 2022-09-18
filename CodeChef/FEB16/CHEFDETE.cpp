#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> v(n + 1, false);
    for (int i = 1; i <= n; i++) {
        int hold;
        cin >> hold;
        v[hold] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            cout << i << ' ';
        }
    }
    return 0;
}