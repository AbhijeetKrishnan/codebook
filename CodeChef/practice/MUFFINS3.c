#include <stdio.h>

int main()
{
    int T;
    int N;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &N);
        printf("%d\n", ((N / 2) + 1));
    }
    return 0;
}