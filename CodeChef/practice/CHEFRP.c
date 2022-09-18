#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    int n;
    int *a;
    int i;
    int min, sum;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        a = malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        min = a[0];
        sum = 0;
        for (i = 1; i < n; i++)
        {
            if (a[i] < min)
            {
                sum += min;
                min = a[i];
            }
            else
            {
                sum += a[i];
            }
        }
        if (min < 2)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", sum + 2);
        }
    }
    return 0;
}