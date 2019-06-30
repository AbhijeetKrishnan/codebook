#include <iostream>
#include <cmath>

using namespace std;
typedef long long int lli;

int main()
{
    lli l, r, k;
    cin >> l >> r >> k;
    lli start_pow = (lli)(log(l) / log(k));
    lli start_val = pow(k, start_pow);
    while (start_val > l) start_val /= k;
    while (start_val < l) start_val *= k;
    if (start_val > r)
    {
        cout << "-1\n";
    }
    else
    {
        while (start_val <= r)
        {
            cout << start_val << ' ';
            start_val *= k;
        }
    }
    return 0;
}
