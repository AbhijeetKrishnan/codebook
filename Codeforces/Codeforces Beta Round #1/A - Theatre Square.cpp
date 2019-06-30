#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m, a;
    cin >> n >> m >> a;
    long long int count = ceil((double)n / a) * ceil((double)m / a);
    cout << count << '\n';
    return 0;
}
