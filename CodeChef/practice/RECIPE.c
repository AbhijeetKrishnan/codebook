#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }
    else if (a > b)
    {
        return gcd(a % b, b);
    }
    else
    {
        return gcd(a, b % a);
    }
}
int main()
{
    int t;
    int n;
    int *ingredient;
    int current_gcd;
    int i;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        ingredient = (int*)malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &ingredient[i]);
        }
        current_gcd = ingredient[0];
        for (i = 1; i < n; i++)
        {
            current_gcd = gcd(current_gcd, ingredient[i]);
        }
        for (i = 0; i < n; i++)
        {
            ingredient[i] /= current_gcd;
            printf("%d ", ingredient[i]);
        }
        printf("\n");
    }
    return 0;
}