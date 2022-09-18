#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 100000
int main()
{
    int t, n;
    int* piles;
    int nop;
    int max_count;
    int count[MAX_NUM];
    int i;
    scanf("%d", &t);
    while (t--)
    {
        max_count = 0;
        nop = 0;
        for(i = 0; i < MAX_NUM; i++)
        {
            count[i] = 0;
        }
        scanf("%d", &n);
        piles = (int*)malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &piles[i]);
        }
        for (i = 0; i < n; i++)
        {
            count[piles[i] - 1]++;
            if (count[piles[i] - 1] > max_count)
            {
                max_count = count[piles[i] - 1];
            }
        }
        nop = n - max_count;
        printf("%d\n", nop);
        free(piles);
    }
    return 0;
}