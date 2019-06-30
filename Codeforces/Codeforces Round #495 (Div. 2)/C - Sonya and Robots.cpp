#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int n;
int tmp;
vector<int> v[N];

enum type {LEFT, RIGHT, SINGLE};

struct obj {
    int pos;
    type t;
    obj(int p, type tt): pos {p}, t {tt} {}
    
};

bool cmp(obj i, obj j) {
    return i.pos < j.pos;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v[tmp - 1].push_back(i);
    }

    vector<obj> a;
    for (int i = 0; i < N; ++i) {
        if (v[i].size() >= 2) {
            a.push_back(obj(v[i].front(), LEFT));
            a.push_back(obj(v[i].back(), RIGHT));
        }
        else if (v[i].size() == 1) {
            a.push_back(obj(v[i].front(), SINGLE));
        }
    }
    sort(a.begin(), a.end(), cmp);
    int len = a.size();
    int pre[len+1];
    pre[0] = 0;
    for (int i = 1; i <= len; ++i) {
        if (a[i-1].t != LEFT) {
            pre[i] = pre[i-1] + 1;
        }
        else {
            pre[i] = pre[i-1];
        }
    }

    long long ans = 0;
    for (int i = 0; i + 1 < len; ++i) {
        if (a[i].t != RIGHT) {
            ans += pre[len] - pre[i+1];
        }
    }
    cout << ans;
    return 0;
}