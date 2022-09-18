#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        int cuts = 0;
        scanf("%d %d", &n, &m);
        int *a = malloc(sizeof(int) * m);
        int i;
        for (i = 0; i < m; i++)
        {
            scanf("%d", &a[i]);
        }
        if (m == n)
        {
            cuts = m / 2;
        }
        else if (m == 1)
        {
            cuts = 0;
        }
        else
        {
            int j, tmp;
            i = -1;
            j = 0;
            while (j < m)
            {
                if (a[j] <= m - 1)
                {
                    i++;
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
                j++;
            }
            qsort(a, i + 1, sizeof(int), compare);
            i = 0;
            j = m - 1;
            while (i < j)
            {
                if (j - i > a[i])
                {
                    cuts += a[i];
                    j -= a[i];
                    i++;
                }
                else
                {
                    cuts += j - i;
                    break;
                }
            }
        }
        printf("%d\n", cuts);
    }
    return 0;
}