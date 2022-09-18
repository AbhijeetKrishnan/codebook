#include <bits/stdc++.h>

using namespace std;

inline int calculate_subarrays(int i, int l, int r) {
    return (r - i) * (i - l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> left(n), right(n);
    vector<int> stack;
    for (int i = 0; i < n; i++) {
        while (not stack.empty() and a[i] >= a[stack.back()]) {
            stack.pop_back();
        }
        left[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }
    stack.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (not stack.empty() and a[i] > a[stack.back()]) {
            stack.pop_back();
        }
        right[i] = stack.empty() ? n : stack.back();
        stack.push_back(i);
    }
    vector<pair<int, int>> tmp(n);
    for (int i = 0; i < n; i++) {
        tmp[i].first = a[i];
        tmp[i].second = calculate_subarrays(i, left[i], right[i]);
    }
    sort(tmp.begin(), tmp.end());
    a.clear();
    vector<int> prefix_sum;
    prefix_sum.push_back(0);
    for (int i = 0; i < n; ) {
        a.push_back(tmp[i].first);
        prefix_sum.push_back(prefix_sum.back() ^ tmp[i].second);
        int j;
        for (j = i + 1; j < n and tmp[i].first == tmp[j].first; j++) {
            prefix_sum.back() ^= tmp[j].second;
        }
        i = j;
    }
    n = a.size();
    for (int i = 0; i < m; i++) {
        char c, x, y;
        int k;
        cin >> c >> k >> x;
        y = (x == 'C') ? 'D' : 'C';
        int num_values;
        if (c == '>') {
            auto itr = upper_bound(a.begin(), a.end(), k);
            int idx = itr - a.begin();
            num_values = prefix_sum[n] ^ prefix_sum[idx];
        }
        else if (c == '<') {
            auto itr = lower_bound(a.begin(), a.end(), k);
            int idx = itr - a.begin();
            num_values = prefix_sum[idx] ^ prefix_sum[0];
        }
        else {
            auto itr = lower_bound(a.begin(), a.end(), k);
            int idx = itr - a.begin();
            if (a[idx] == k) {
                num_values = prefix_sum[idx + 1] ^ prefix_sum[idx];
            }
            else {
                num_values = 0;
            }
        }
        if (num_values % 2 == 0) {
            cout << y;
        }
        else {
            cout << x;
        }
    }
    return 0;
}