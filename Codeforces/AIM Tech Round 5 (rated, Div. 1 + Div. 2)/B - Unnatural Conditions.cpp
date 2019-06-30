#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string a = string(2230, '4');
    string b = string(2230, '5');
    b[2229] = '6';
    cout << a << "\n" << b;
    return 0;
}