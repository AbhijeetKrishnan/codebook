#include <stdio.h>
#define YES_AMBIGUOUS 1
#define NO_AMBIGUOUS 0

int main()
{
    int n;
    int i, flag;
    while (1)
    {
        flag = YES_AMBIGUOUS;
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        int input[n], output[n];
        for(i = 0; i < n; i++)
        {
            scanf("%d", &input[i]);
            output[ input[ i ] - 1 ] = i + 1;
        }
        for (i = 0; (i < n) && (flag == YES_AMBIGUOUS); i++)
        {
            if (input[ i ] != output[ i ])
                flag = NO_AMBIGUOUS;
        }
        if (flag == YES_AMBIGUOUS)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");
    }
    return 0;
}