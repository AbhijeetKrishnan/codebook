#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    unsigned int n;
    int m;
    int *notes;
    unsigned int i, j, limit;
    int sum;
    int flag;
    scanf("%d", &t);
    while (t--)
    {
        flag = 0;
        scanf ("%u %u", &n, &m);
        notes = (int*)malloc(n * sizeof(int));
        i = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%u", &notes[i]);
        }
        limit = 2 << n;
        for (i = 0; (i < limit) && (flag == 0); i++)
        {
            sum = 0;
            for (j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    sum += notes[j];
                }
            }
            if (sum == m)
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}