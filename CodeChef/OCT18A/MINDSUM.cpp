#include <bits/stdc++.h>

using namespace std;

long long int digit_sum(long long int n) {
    long long int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        long long int n, _n, d;
        cin >> n >> d;
        int nm9 = (int)(n % 9);
        if (nm9 == 0) {
            nm9 = 9;
        }
        int dm9 = (int)(d % 9);
        int min_val = nm9;
        int add_times = 0;
        int lim = 9;
        if (dm9 == 0) {
            lim = 0;
        }
        else if (dm9 == 3 or dm9 == 6) {
            lim = 3;
        }
        for (int i = 0; i < lim; ++i) {
            nm9 = (nm9 + dm9) % 9;
            if (nm9 == 0) {
                nm9 = 9;
            }
            if (nm9 < min_val) {
                min_val = nm9;
                add_times = i + 1;
            }
        }
        _n = n + d * add_times;
        int dig_times = 0;
        while (_n > 9) {
            _n = digit_sum(_n);
            dig_times++;
        }
        if (dig_times > 2) {
            vector<int> perm;
            for (int i = 0; i < add_times; ++i) {
                perm.push_back(0);
            }
            for (int i = 0; i + 1 < dig_times; ++i) {
                perm.push_back(1);
            }
            do {
                _n = n;
                for (auto e: perm) {
                    if (e == 0) {
                        _n += d;
                    }
                    else {
                        _n = digit_sum(_n);
                    }
                }
                if (_n == min_val) {
                    dig_times--;
                    break;
                }
            } while (next_permutation(perm.begin(), perm.end()));
        }
        cout << min_val << " " << (add_times + dig_times) << "\n";
    }
    return 0;
}