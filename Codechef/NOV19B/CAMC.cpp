#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <tuple>

using namespace std;

const int INF = 1e9;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(m, vector<int>());
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            a[i % m].push_back(tmp);
        }
        for (int i = 0; i < m; i++) {
            sort(a[i].begin(), a[i].end());
        }
        vector<tuple<int, int, int>> min_heap;
        int max_val = 0;
        tuple<int, int, int> max_ele;
        for (int i = 0; i < m; i++) {
            min_heap.push_back(make_tuple(a[i][0], i, 0));
            if (a[i][0] > max_val) {
                max_val = a[i][0];
                max_ele = make_tuple(a[i][0], i, 0);
            }
        }
        make_heap(min_heap.begin(), min_heap.end(), greater<tuple<int, int, int>>());
        int diff, min_diff = INF;
        while (true) {
            diff = get<0>(max_ele) - get<0>(min_heap.front());
            min_diff = min(min_diff, diff);
            if (get<2>(min_heap.front()) + 1 < a[get<1>(min_heap.front())].size()) {
                pop_heap(min_heap.begin(), min_heap.end(), greater<tuple<int, int, int>>());
                tuple<int, int, int> old_min_ele = min_heap.back();
                min_heap.pop_back();
                min_heap.push_back(make_tuple(a[get<1>(old_min_ele)][get<2>(old_min_ele) + 1], get<1>(old_min_ele), get<2>(old_min_ele) + 1));
                if (get<0>(min_heap.back()) > max_val) {
                    max_val = get<0>(min_heap.back());
                    max_ele = min_heap.back();
                }
                push_heap(min_heap.begin(), min_heap.end(), greater<tuple<int, int, int>>());
            }
            else {
                break;
            }
        }
        cout << min_diff << "\n";
    }
    return 0;
}