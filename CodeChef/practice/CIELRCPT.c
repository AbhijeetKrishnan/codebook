#include <stdio.h>

int num_of_ones(int inp)
{
    int count = 0;
    while(inp)
    {
        count += inp & 1;
        inp >>= 1;
    }
    return count;
}
int main()
{
    int T, p;
    int rem, i;
    int max_menus;
    scanf("%d", &T);
    for(i = 1; i <= T; i++)
    {
        scanf("%d", &p);
        max_menus = p / 2048;
        rem = p % 2048;
        max_menus += num_of_ones(rem);
        printf("%d\n", max_menus);
    }
}