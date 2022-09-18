#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int sum(int** triangle, int x, int y, int limit, int** cache)
{
    int ret_val;
    if (cache[x][y] != -1)
    {
        ret_val = cache[x][y];
    }
    else if (x == limit)
    {
        ret_val = triangle[x][y];
    }
    else
    {
        ret_val = cache[x][y] = triangle[x][y] + max(sum(triangle, x + 1, y, limit, cache), sum(triangle, x + 1, y + 1, limit, cache));
    }
    return ret_val;
}
int main()
{
    int T;
    int n;
    int i, j;
    int** triangle;
    int** cache;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        triangle = (int**)malloc(n * sizeof(int*));
        cache = (int**)malloc(n * sizeof(int*));
        for(i = 1; i <= n; i++)
        {
            triangle[i - 1] = (int*)malloc(i * sizeof(int));
            cache[i - 1] = (int*)malloc(i * sizeof(int));
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= i; j++)
            {
                cache[i][j] = -1;
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= i; j++)
            {
                scanf("%d", &triangle[i][j]);
            }
        }
        printf("%d\n", sum(triangle, 0, 0, n - 1, cache));
        for (i = 0; i < n; i++)
        {
            free(triangle[i]);
            free(cache[i]);
        }
        free(triangle);
        free(cache);
    }
    return 0;
}