#include <stdio.h>
int main()
{
    int n, m;
    int angle = 0;
    int i, j;
    scanf("%d %d", &n, &m);
    int a[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    while (m--)
    {
        scanf("%d", &angle);
        angle = angle % 360;
        switch(angle)
        {
            printf("%d\n", angle);
            case 90:
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        printf("%d ", a[n - 1 - j][i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 180:
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        printf("%d ", a[n - 1 - i][n - 1 - j]);
                    }
                    printf("\n");
                }
                break;
            }
            case 270:
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        printf("%d ", a[j][n - 1 - i]);
                    }
                    printf("\n");
                }
                break;
            }
            default:
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        printf("%d ", a[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
        }
        printf("\n");
    }
    return 0;
}