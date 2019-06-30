#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

int main()
{
    double x1, y1, r1;
    cin >> x1 >> y1 >> r1;
    double x2, y2, r2;
    cin >> x2 >> y2 >> r2;
    double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    //cout << d << '\n';
    double ans;
    if (d > (r1 + r2))
    {
        ans = 0;
    }
    else if (d <= abs(r1 - r2))
    {
        ans = PI * min(r1, r2) * min(r1, r2);
    }
    else
    {
        double term1, term2, term3;
        term1 = r1*r1 * acos((d*d + r1*r1 - r2*r2) / (2*d*r1));
        term2 = r2*r2 * acos((d*d + r2*r2 - r1*r1) / (2*d*r2));
        term3 = sqrt((-d + r1 - r2) * (-d - r1 + r2) * (-d + r1 + r2) * (d + r1 + r2)) / 2;
        ans = term1 + term2 - term3;
    }
    //cout << ans << '\n';
    printf("%.20f\n", ans);
    return 0;
}
