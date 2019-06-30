#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, p, q;
    cin >> n >> p >> q;
    string s;
    cin >> s;
    int a = n / p, b = n / q;
    int total = 0;
    bool is_possible = false;
    int p1, p2;
    for (int i = 0; i <= a && !is_possible; i++)
    {
        for (int j = 0; j <= b && !is_possible; j++)
        {
            if (p * i + q * j == n)
            {
                is_possible = true;
                p1 = i;
                p2 = j;
            }
        }
    }
    //cout << p1 << ' ' << p2 << '\n';
    if (is_possible)
    {
        cout << p1 + p2 << '\n';
        int i = 0;
        while (p1 != 0)
        {
            string tmp = s.substr(i, p);
            cout << tmp << '\n';
            i += p;
            p1--;
        }
        while (p2 != 0)
        {
            string tmp = s.substr(i, q);
            cout << tmp << '\n';
            i += q;
            p2--;
        }
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}
