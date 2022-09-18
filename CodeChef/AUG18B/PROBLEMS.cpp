#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int p, s;
    cin >> p >> s;
    vector<pair<int, int>> difficulty(p);
    for (int i = 0; i < p; i++) {
        difficulty[i].first = 0;
        difficulty[i].second = i + 1;
    }
    vector<vector<pair<int, int>>> subtasks(p, vector<pair<int, int>>(s));
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < s; j++) {
            cin >> subtasks[i][j].first;
        }
        for (int j = 0; j < s; j++) {
            cin >> subtasks[i][j].second;
        }
    }
    for (int i = 0; i < p; i++) {
        sort(subtasks[i].begin(), subtasks[i].end());
        for (int j = 1; j < s; j++) {
            if (subtasks[i][j].second < subtasks[i][j-1].second) {
                difficulty[i].first++;
            }
        }
    }
    sort(difficulty.begin(), difficulty.end());
    for (int i = 0; i < p; i++) {
        cout << difficulty[i].second << "\n";
    }
    return 0;
}