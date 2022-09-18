#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **substring;
    int *one_count, *zero_count;
    int t;
    int n; //length of string
    int q; //number of queries
    int lim; //number of 1s and 0s must be less than this
    int left, right; //left and right indexes of queries
    char *input;
    int i, j, k, l, m, p;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d", &n, &lim, &q);
        input = malloc((n + 1) * sizeof(char));
        substring = malloc(((n * (n + 1)) / 2) * sizeof(int*));
        one_count = malloc((n + 1) * sizeof(int));
        zero_count = malloc((n + 1) * sizeof(int));
        one_count[0] = zero_count[0] = 0;
        for (i = 0; i < n; i++)
        {
            substring[i] = malloc((i + 1) * sizeof(int));
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= i; j++)
            {
                substring[i][j] = 0;
            }
        }
        scanf("%s", input);
        for (i = 1; i <= n; i++)
        {
            if (input[i - 1] == '0')
            {
                one_count[i] = one_count[i - 1] + 1;
                zero_count[i] = zero_count[i - 1];
            }
            else
            {
                one_count[i] = one_count[i - 1];
                zero_count[i] = zero_count[i - 1] + 1;
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = i, k = 0; j < n; j++, k++)
            {
                for (l = 0; l < j - k + 1; l++)
                {
                    for (m = k + l, p = k; m - k < j - k + 1; m++, p++)
                    {
                        if ((one_count[m + 1] - one_count[p] <= lim) && (zero_count[m + 1] - zero_count[p] <= lim))
                        {
                            //printf("(%d, %d): %d\n", k, j, substring[j][k]);
                            substring[j][k]++;
                        }
                    }
                }
                //printf("(%d, %d): %d\n", k, j, substring[j][k]);
            }
        }
        while (q--)
        {
            scanf("%d %d", &left, &right);
            printf("%d\n", substring[right - 1][left - 1]);
        }
        //free(input);
        for (i = 0; i < n; i++)
        {
            //printf("Before freeing substring[%d]\n", i);
            free(substring[i]);
            //printf("Freed substring[%d] successfully\n", i);
        }
        //free(substring);
        //free(one_count);
        //free(zero_count);
    }
    return 0;
}