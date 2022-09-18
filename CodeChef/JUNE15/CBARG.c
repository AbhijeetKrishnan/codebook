#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    int n;
    long long int *store;
    int i;
    long long int current, total;
    scanf("%d", &t);
    while (t--)
    {
        current = 0;
        total = 0;
        scanf("%d", &n);
        store = malloc(n * sizeof(long long int));
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &store[i]);
            if (store[i] - current >= 0)
            {
                total += store[i] - current;
            }
            current = store[i];
        }
        printf("%lld\n", total);
    }
    return 0;
}