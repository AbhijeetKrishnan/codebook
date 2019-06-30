#include <bits/stdc++.h>

using namespace std;

class vec {
public:
    int x;
    int y;
    vec(int _x, int _y) {
        x = _x;
        y = _y;
    }
    long long mag() const {
        return 1LL * x * x + 1LL * y * y;
    }
    vec operator+(const vec& a) {
        return vec(a.x + x, a.y + y);
    }
    vec operator-(const vec& a) {
        return vec(x - a.x, y - a.y);
    }
};

bool cmp(const vec& a, const vec& b) {
    return a.mag() > b.mag();
}

int main() {
    int n;
    cin >> n;
    vector<vec> v;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v.push_back(vec(x, y));
    }
    sort(v.begin(), v.end(), cmp);
    vec c = v[0];
    cout << "1 ";
    for (int i = 1; i < n; ++i) {
        vec p1 = c + v[i];
        vec p2 = c - v[i];
        if (p1.mag() < p2.mag()) {
            c = p1;
            cout << "1 ";
        }
        else {
            c = p2;
            cout << "-1 ";
        }
    }
    return 0;
}