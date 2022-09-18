#include <stdio.h>
int main()
{
    int t;
    int n, k;
    int i;
    int max;
    scanf("%d", &t);
    while (t--)
    {
        max = 0;
        scanf("%d %d", &n, &k);
        for (i = k; i > 1; i--)
        {
            if (n % i > max) max = n % i;
        }
        printf("%d\n", max);
    }
    return 0;
}