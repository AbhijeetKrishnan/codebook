/**
 * Author: rashomon
 * Platform: Codechef
 * URL: https://www.codechef.com/COOK77/problems/CHEFSETC
 * Problem Name: Chef and Subset
 */
 
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int v[4];
        cin >> v[0] >> v[1] >> v[2] >> v[3];
        int sum = v[0] + v[1] + v[2] + v[3];
        bool is_possible = false;
        for (int i = 0; i < 4 && !is_possible; ++i) {
            if (v[i] == 0 || sum - v[i] == 0) {
                is_possible = true;
                break;
            }
        }
        for (int i = 0; i + 1 < 4 && !is_possible; ++i) {
            for (int j = i + 1; j < 4 && !is_possible; ++j) {
                if (v[i] + v[j] == 0) {
                    is_possible = true;
                    break;
                }
            }
        }
        if (sum == 0) {
            is_possible = true;
        }
        if (is_possible) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}