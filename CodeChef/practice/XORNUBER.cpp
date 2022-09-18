#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        if (n == 1)
        {
            cout << "2" << endl;
        }
        else if (!(n & (n + 1)))
        {
            cout << (n >> 1) << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}