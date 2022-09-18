#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int t;
    int n;
    long long int k, p, l, total, tmp;
    int *a;
    int i;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %lld", &n, &k);
        a = malloc(sizeof(int) * n);
        l = 0;
        total = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] > l)
            {
                tmp = a[i] - l;
                p = ceil((double)tmp / k);
                l = (tmp % k == 0 ? 0 : k - (tmp % k));
                total += p;
            }
            else
            {
                l -= a[i];
            }
            if (l > 0) l--;
        }
        printf("%lld\n", total);
        free(a);
    }
    return 0;
}