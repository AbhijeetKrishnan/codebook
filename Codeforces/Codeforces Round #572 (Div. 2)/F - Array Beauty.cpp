#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int MOD = 998244353;

template<typename T>
unordered_set<T> get_union(unordered_set<T>& a, unordered_set<T>& b) {
    unordered_set<T> result = a;
    result.insert(b.begin(), b.end());
    return result;
}

void calculate_nck_table(vector<int>& table, int n, int k) {
    table.resize(n + 1, 1);
    for (int itr = 1; itr <= k; itr++) {
        for (int i = 1; i < n + 1 - itr; i++) {
            table[i] += table[i - 1];
        }
    }
    table.resize(n + 1 - k);
}

int nck(int n, vector<int>& table) {
    int k = table[1] - 1;
    if (n < k) {
        return 0;
    }
    else {
        return table[n - k];
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for (auto &e: a) {
        cin >> e;
    }
    vector<int> table;
    calculate_nck_table(table, n, k - 2);
    // for (auto e: table) {
    //     cout << e << " ";
    // }
    // cout << "\n";
    vector<tuple<int, int, int>> differences;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            differences.push_back({abs(a[i] - a[j]), i, j});
        }
    }
    sort(differences.begin(), differences.end());
    // for (auto [diff, i, j]: differences) {
    //     printf("%d %d %d\n", diff, a[i], a[j]);
    // }
    vector<unordered_set<int>> associated(n);
    int ans = 0;
    for (auto [diff, i, j]: differences) {
        int total_seen = get_union(associated[i], associated[j]).size();
        // (n - 2 - total_seen) C k
        int times = nck(n - 2 - total_seen, table);
        //printf("Total seen: %d | Times: %d\n", total_seen, times);
        ans = (ans + ((long long int)diff * nck(n - 2 - total_seen, table)) % MOD) % MOD;
        associated[i].insert(j);
        associated[j].insert(i);
    }
    cout << ans << "\n";
    return 0;
}