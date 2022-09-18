#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n1, n2;
        long long int m;
        cin >> n1 >> n2 >> m;
        if (min(n1, n2) <= ((m * (m + 1)) / 2))
            cout << max(n1, n2) - min(n1, n2) << '\n';
        else
            cout << (n1 - (m * (m + 1) / 2)) + (n2 - (m * (m + 1) / 2)) << '\n';
    }
    return 0;
}