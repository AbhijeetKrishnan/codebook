#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int result;
        result = ((long long int)n * (n + 1)) / 2;
        int lg = floor(log2(n)) + 1;
        long long int power = (1 << (long long int)lg) - 1;
        result -= 2 * power;
        cout << result << '\n';
    }
    return 0;
}
