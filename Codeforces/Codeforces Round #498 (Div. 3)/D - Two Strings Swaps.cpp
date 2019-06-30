#include <bits/stdc++.h>

using namespace std;

bool check(char al, char ar, char bl, char br) {
    if (al == ar and bl == br) {
        return true;
    }
    else if (al == bl and ar == br) {
        return true;
    }
    else if (al == br and ar == bl) {
        return true;
    }
    else {
        return false;
    }
}

int check_all(char al, char ar, char bl, char br) {
    if (check(al, ar, bl, br)) {
        return 0;
    }
    else if (check(al, bl, bl, br)) {
        return 1;
    }
    else if (check(al, al, bl, br)) {
        return 1;
    }
    else if (check(ar, ar, bl, br)) {
        return 1;
    }
    else if (check(al, br, bl, br)) {
        return 1;
    }
    else if (check(br, ar, bl, br)) {
        return 1;
    }
    else if (check(bl, ar, bl, br)) {
        return 1;
    }
    else if (check(bl, br, bl, br)) {
        return 2;
    }
}

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    int ans = 0;
    if (n & 1) {
        if (a[n/2] != b[n/2]) {
            ans++;
        }
    }
    for (int i = 0; i < n / 2; ++i) {
        char al = a[i], ar = a[n - 1 - i];
        char bl = b[i], br = b[n - 1 - i];
        ans += check_all(al, ar, bl, br);
        //cout << i << " " << al << " " << ar << " " << bl << " " << br << " " << ans << "\n";
    }
    cout << ans;
    return 0;
}