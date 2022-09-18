#include <iostream>

typedef long long int lli;
using namespace std;

lli gcd(lli a, lli b)
{
    lli tmp;
    while (b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

bool has_unique_prime(lli a, lli b)
{
    bool ret_val;
    if (b == 1)
        ret_val = false;
    else
    {
        lli g = gcd(a, b);
        if (g == 1)
            ret_val = true;
        else
            ret_val = has_unique_prime(a, b / g);
    }
    return ret_val;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lli a, b;
        cin >> a >> b;
        if (has_unique_prime(a, b))
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}