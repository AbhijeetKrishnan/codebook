#include <stdio.h>

int main()
{
    int T;
    int N;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        if (N % 2 == 0)
        {
            printf("%d\n", N);
        }
        else
        {
            printf("%d\n", (N-1));
        }
    }
    return 0;
}