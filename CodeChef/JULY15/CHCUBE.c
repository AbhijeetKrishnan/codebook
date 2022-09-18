#include <stdio.h>
#include <string.h>
int is_equal(int a, int b, int c)
{
    if (a == b && a == c && b == c)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int t;
    char a[6][7];
    int i;
    int c[6];
    scanf("%d", &t);
    while (t--)
    {
        memset(c, 0, 6 * sizeof(int));
        for (i = 0; i < 6; i++)
        {
            scanf("%s", a[i]);
        }
        for (i = 0; i < 6; i++)
        {
            if (strcmp(a[i], "black") == 0)
            {
                c[i] = 0;
            }
            else if (strcmp(a[i], "blue") == 0)
            {
                c[i] = 1;
            }
            else if (strcmp(a[i], "red") == 0)
            {
                c[i] = 2;
            }
            else if (strcmp(a[i], "green") == 0)
            {
                c[i] = 3;
            }
            else if (strcmp(a[i], "yellow") == 0)
            {
                c[i] = 4;
            }
            else if (strcmp(a[i], "orange") == 0)
            {
                c[i] = 5;
            }
        }
        if (is_equal(c[0], c[2], c[4]) || is_equal(c[1], c[2], c[4]) || is_equal(c[1], c[3], c[4]) || is_equal(c[0], c[3], c[4]) || is_equal(c[0], c[2], c[5]) || is_equal(c[1], c[2], c[5]) || is_equal(c[1], c[3], c[5]) || is_equal(c[0], c[3], c[5]))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }

    }
    return 0;
}