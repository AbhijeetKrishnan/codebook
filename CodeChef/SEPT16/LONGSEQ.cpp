/**
 * Author: rashomon
 * Platform: Codechef
 * URL: https://www.codechef.com/SEPT16/problems/LONGSEQ
 * Problem Name: Chef and digits of a number
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
        string d;
        cin >> d;
        int n = d.size();
        int ones = 0, zeroes = 0;
        for (char c : d) {
            if (c == '1') ++ones;
            else ++zeroes;
        }
        bool ans;
        if (zeroes == n - 1 && ones == 1) {
            ans = true;
        }
        else if (zeroes == 1 && ones == n - 1) {
            ans = true;
        }
        else {
            ans = false;
        }
        if (ans) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}