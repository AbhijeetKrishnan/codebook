#include <stdio.h>
int main()
{
    int t;
    int a, b;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &a, &b);
        if (a % 2 == 0 || b % 2 == 0) printf("Tuzik\n");
        else printf("Vanka\n");
    }
    return 0;
}