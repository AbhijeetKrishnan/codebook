/**
 * Author: rashomon
 * Platform: Codechef
 * URL: https://www.codechef.com/AUG16/problems/CHCHCL
 * Problem Name: Chef and Chocolate
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<int, vector<int>> graph;
typedef unordered_map<int, vector<pair<int, int>>> weighted_graph;

const int M = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n % 2 == 0 || m % 2 == 0) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}