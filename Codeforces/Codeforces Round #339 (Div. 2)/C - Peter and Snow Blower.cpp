#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef long long int lli;
const double PI = 3.1415926535897932;

int main()
{
    int n, p_x, p_y;
    cin >> n >> p_x >> p_y;
    int x, y;
    cin >> x >> y;
    lli max, min;
    max = min = (lli)(x - p_x) * (x - p_x) + (lli)(y - p_y) * (y - p_y);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        lli val = (lli)(x - p_x) * (x - p_x) + (lli)(y - p_y) * (y - p_y);
        if (val > max)
            max = val;
        else if (val < min)
            min = val;
    }
    double result = PI * (max - min);
    printf("%.16f\n", result);
    return 0;
}
