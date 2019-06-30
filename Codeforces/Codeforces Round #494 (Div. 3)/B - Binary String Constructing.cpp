#include <bits/stdc++.h>

using namespace std;

string solve(int a, int b, int x) {
    int grps_max = (x + 1) / 2 + (x + 1) % 2;
    int grps_min = (x + 1) / 2;
    int mx_grp_size = max(a, b) / grps_max;
    int mn_grp_size = min(a, b) / grps_min;
    char mx = (a > b) ? '0' : '1';
    char mn = (a > b) ? '1' : '0';
    string ans = "";
    if (grps_max == grps_min) {
        for (int i = 0; i + 1 < grps_min; ++i) {
            for (int j = 0; j < mx_grp_size; ++j) {
                ans += mx;
            }
            for (int j = 0; j < mn_grp_size; ++j) {
                ans += mn;
            }
        }
        for (int j = 0; j < max(a, b) - (grps_max - 1) * mx_grp_size; ++j) {
                ans += mx;
        }
        for (int j = 0; j < min(a, b) - (grps_min - 1) * mn_grp_size; ++j) {
            ans += mn;
        }
    }
    else {
        for (int i = 0; i + 1 < grps_min; ++i) {
            for (int j = 0; j < mx_grp_size; ++j) {
                ans += mx;
            }
            for (int j = 0; j < mn_grp_size; ++j) {
                ans += mn;
            }
        }
        for (int j = 0; j < mx_grp_size; ++j) {
                ans += mx;
        }
        for (int j = 0; j < min(a, b) - (grps_min - 1) * mn_grp_size; ++j) {
            ans += mn;
        }
        for (int i = 0; i < max(a, b) - grps_min * mx_grp_size; ++i) {
            ans += mx;
        }
    }
    return ans;
}

bool verify(string s, int a, int b, int x) {
    int cnt_a = 0, cnt_b = 0, shifts = 0;
    for (char c : s) {
        if (c == '0')
            cnt_a++;
        else
            cnt_b++;
    }
    for (int i = 0; i + 1 < s.length(); ++i) {
        if (s[i] != s[i+1])
            shifts++;
    }
    if (cnt_a == a && cnt_b == b && shifts == x) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    
    int a, b, x;
    cin >> a >> b >> x;
    
    cout << solve(a, b, x);
    return 0;
}