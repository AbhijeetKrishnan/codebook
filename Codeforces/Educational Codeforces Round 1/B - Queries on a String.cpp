#include <iostream>

using namespace std;

void modify(string& s, int l, int r, int k)
{
    int length = r - l + 1;
    string tmp(length, ' ');
    for (int i = l; i <= r; i++)
    {
        tmp[(i-l + k) % length] = s[i];
    }
    for (int i = l; i <= r; i++)
    {
        s[i] = tmp[i-l];
    }
}

int main()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        modify(s, l-1, r-1, k);
    }
    cout << s << '\n';
    return 0;
}
