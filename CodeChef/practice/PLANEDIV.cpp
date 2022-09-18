#include <iostream>
#include <set>
#include <map>

using namespace std;

int gcd(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main()
{
    int t;
    cin >> t;
    map<pair<int, int>, set<double>> lines;
    while (t--)
    {
        lines = {};
        int n;
        cin >> n;
        while (n--)
        {
            int a, b;
            double c;
            cin >> a >> b >> c;
            int gcd_ab = gcd(a, b);
            //cout << gcd_ab << '\n';
            a /= gcd_ab;
            b /= gcd_ab;
            c  = (double)c / gcd_ab;
            lines[make_pair(a, b)].insert(c);
        }
        size_t ans = 0;
        for (auto line : lines)
        {
            if (line.second.size() > ans)
                ans = line.second.size();
        }
        cout << ans << '\n';
    }
}