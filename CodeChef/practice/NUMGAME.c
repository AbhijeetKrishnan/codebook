#include <stdio.h>

int main()
{
    int T;
    int N;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        if (N % 2 == 0)
            printf("ALICE\n");
        else
            printf("BOB\n");
    }
    return 0;
}