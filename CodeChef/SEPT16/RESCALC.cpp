/**
 * Author: rashomon
 * Platform: Codechef
 * URL: https://www.codechef.com/SEPT16/problems/RESCALC
 * Problem Name: Chef and calculation
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
        int n;
        cin >> n;
        vector<int> c(n);
        vector<vector<int>> types(n, vector<int>(6, 0));
        vector<pair<int, int>> score(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
            for (int j = 0; j < c[i]; ++j) {
                int type;
                cin >> type;
                ++types[i][type-1];
            }
        }
        for (int i = 0; i < n; ++i) {
            sort(types[i].begin(), types[i].end());
            int bonus = types[i][0] * 4;
            int reduce = types[i][0];
            types[i][1] -= reduce;
            bonus += types[i][1] * 2;
            reduce += types[i][1];
            types[i][2] -= reduce;
            bonus += types[i][2];
            score[i].first = c[i] + bonus;
            score[i].second = i;
        }
        sort(score.rbegin(), score.rend());
        if (n > 1 && score[0].first == score[1].first) {
            cout << "tie\n";
        }
        else if (score[0].second == 0) {
            cout << "chef\n";
        }
        else {
            cout << score[0].second + 1 << '\n';
        }
    }
    return 0;
}