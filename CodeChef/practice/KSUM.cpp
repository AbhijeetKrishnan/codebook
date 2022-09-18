#include <bits/stdc++.h>

using namespace std;

vector<long long int> a;

bool cmp(const pair<int, int>& p, const pair<int, int>& q) {
    long long int p_sum = a[p.second + 1] - a[p.first];
    long long int q_sum = a[q.second + 1] - a[q.first];
    return p_sum < q_sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    a.resize(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    vector<pair<int, int>> heap;
    set<pair<int, int>> seen;
    heap.push_back({0, n - 1});
    seen.insert(make_pair(0, n - 1));
    for (int i = 0; i < k; i++) {
        pop_heap(heap.begin(), heap.end(), cmp);
        pair<int, int> max = heap.back(); heap.pop_back();
        long long int sum = a[max.second + 1] - a[max.first];
        cout << sum << " ";
        if (max.first < max.second) {
            pair<int, int> p1 = {max.first, max.second - 1}, p2 = {max.first + 1, max.second};
            if (seen.find(p1) == seen.end()) {
                heap.push_back(p1);
                push_heap(heap.begin(), heap.end(), cmp);
                seen.insert(p1);
            }
            if (seen.find(p2) == seen.end()) {
                heap.push_back(make_pair(max.first + 1, max.second));
                push_heap(heap.begin(), heap.end(), cmp);
                seen.insert(p2);
            }
        }
    }
    cout << "\n";
    return 0;
}