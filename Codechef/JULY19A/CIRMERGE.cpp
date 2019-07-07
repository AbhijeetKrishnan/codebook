#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &e: v) {
            cin >> e;
        }
        int penalty = 0;
        for (int itr = 0; itr + 1 < n; itr++) {
            int min_penalty = INT_MAX;
            int min_index;
            int sz = v.size();
            for (int i = 0; i < sz; i++) {
                int curr_penalty = v[i] + v[(i + 1) % sz];
                if (curr_penalty < min_penalty) {
                    min_penalty = curr_penalty;
                    min_index = i;
                }
            }
            penalty += min_penalty;
            v[min_index] = min_penalty;
            v.erase(v.begin() + ((min_index + 1) % sz));
        }
        cout << penalty << "\n";
    }
    return 0;
}