#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;
        int count = 0;
        while (a & (a - 1))
        {
            a >>= 1;
            count++;
        }
        if (b >= a)
        {
            while (b != a)
            {
                b >>= 1;
                count++;
            }
        }
        else
        {
            while (b != a)
            {
                a >>= 1;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}