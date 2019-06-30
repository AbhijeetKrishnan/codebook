#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    unordered_map<int, set<pair<int, string>>> store;
    scanf("%d %d\n", &n, &m);
    while (n--) {
        string t;
        getline(cin, t);
        istringstream iss(t);
        string name;
        int region, score;
        iss >> name >> region >> score;
        //cout << name << " " << region << " " << score << '\n';
        store[region].insert(make_pair(score, name));
    }
    for (int i = 1; i <= m; ++i) {
        auto itr1 = store[i].end();
        --itr1;
        auto itr2 = itr1;
        --itr2;
        auto itr3 = itr2;
        --itr3;
        if (store[i].size() > 2 && itr2 -> first == itr3 -> first) {
            cout << "?\n";
        }
        else {
            cout << (itr1 -> second) << " " << (itr2 -> second) << '\n';
        }
    }
    return 0;
}
