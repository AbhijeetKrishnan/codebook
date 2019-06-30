#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    return (b.find(a) != string::npos);
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), cmp);
    /*
    for (int i = 0; i < n; ++i) {
        cout << a[i] << "\n";
    }
    */
    for (int i = 1; i < n; ++i) {
        if (a[i].find(a[i-1]) == string::npos) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << "\n";
    }
    return 0;
}