#include <stdio.h>

int main()
{
    unsigned int n, k;
    unsigned int num;
    unsigned int count = 0ul;
    scanf("%lu %lu", &n, &k);
    while (n--)
    {
        scanf("%lu", &num);
        if (num % k == 0)
        {
            count++;
        }
    }
    printf("%lu\n", count);
    return 0;
}