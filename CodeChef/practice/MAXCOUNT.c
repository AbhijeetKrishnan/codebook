#include <stdio.h>
#include <stdlib.h>
#define MAX 10001
int main()
{
    int buckets[MAX];
    int t, n;
    int i, tmp;
    int max, max_index;
    scanf("%d", &t);
    while (t--)
    {
        for (i = 0; i < MAX; i++)
        {
            buckets[i] = 0;
        }
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            buckets[tmp]++;
        }
        max = buckets[1];
        max_index = 1;
        for (i = 2; i < MAX; i++)
        {
            if (buckets[i] > max)
            {
                max = buckets[i];
                max_index = i;
            }
        }
        printf("%d %d\n", max_index, max);
    }
    return 0;
}