#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int hold;
        scanf("%d", &hold);
        v.push_back(hold);
    }

    long long int sum = 0;
    for (int i : v)
    {
        sum += i;
    }
    int lb = floor((float)sum / n), ub = ceil((float)sum / n);
    int gt_total = 0, lt_total = 0;
    for (int i : v)
    {
        if (i <= lb)
        {
            lt_total += lb - i;
        }
        else
        {
            gt_total += i - ub;
        }
    }
    printf("%d", max(lt_total, gt_total));
    return 0;
}
