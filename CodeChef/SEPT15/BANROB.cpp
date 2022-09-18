#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        const double bank_money = 1000000000;
        cout.precision(3);
        cout << fixed;
        int m;
        double p;
        cin >> m >> p;
        double power = pow(p, m);
        double chef_money, colleague_money;
        if (m & 1) //m is odd
        {
            chef_money = (bank_money * (1 + power)) / (1 + p);
            colleague_money = bank_money - chef_money;
        }
        else //m is even
        {
            chef_money = (bank_money * (1 - power)) / (1 + p);
            colleague_money = bank_money - chef_money;
        }
        cout << chef_money << " " << colleague_money << endl;
    }
    return 0;
}