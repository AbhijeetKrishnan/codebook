#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    int n, k;
    int i;
    long long int *a;
    unsigned long long int sum = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &k);
        a = malloc(sizeof(long long int) * n);
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        if (k > 1)
        {
            printf("even\n");
        }
        else
        {
            if (sum & 1)
            {
                printf("even\n");
            }
            else
            {
                printf("odd\n");
            }
        }
        free(a);
    }
    return 0;
}