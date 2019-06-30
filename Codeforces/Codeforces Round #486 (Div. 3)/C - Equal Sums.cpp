#include <bits/stdc++.h>

using namespace std;

class data {
public:
    int val;
    int seq;
    int ind;
    data(int v, int s, int i) {
        val = v;
        seq = s;
        ind = i;
    }
};

bool operator<(const data& lhs, const data& rhs) {
    return lhs.val < rhs.val;
}

class cmp {
public:
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first;
    }
};

int main() {
    int k;
    cin >> k;
    set<data> s;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        int sum = 0;
        set<pair<int, int>, cmp> st;
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            st.insert({tmp, j + 1});
            sum += tmp;
        }
        for (auto e: st) {
            data next = data(sum - e.first, i + 1, e.second);
            auto itr = s.find(next);
            if (itr == s.end()) {
                s.insert(next);
            }
            else {
                cout << "YES\n";
                cout << itr -> seq << " " << itr -> ind << "\n";
                cout << next.seq << " " << next.ind << "\n";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}