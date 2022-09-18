#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    int t;
    cin >> t;
    while (t--)
    {
        bool is_matching = true;
        cin >> s1;
        cin >> s2;
        for (int i = 0; i < s1.length() && is_matching; i++)
        {
            if (s1[i] != '?' && s2[i] != '?' && s1[i] != s2[i])
                is_matching = false;
        }
        if (is_matching)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}