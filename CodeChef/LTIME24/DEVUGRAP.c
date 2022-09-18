#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    int n, k;
    int *a;
    int i;
    unsigned long long int ans;
    int half, tmp;
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d %d", &n, &k);
        //printf("%d %d\n", n, k);
        a = malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        half = k / 2;
        for (i = 0; i < n; i++)
        {
            tmp = a[i] % k;
            if (tmp == a[i])
            {
                ans += k - a[i];
            }
            else if (tmp > half)
            {
                ans += k - tmp;
            }
            else
            {
                ans += tmp;
            }
        }
        printf("%llu\n", ans);
    }
    return 0;
}