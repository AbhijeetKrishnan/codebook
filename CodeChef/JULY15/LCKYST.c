#include <stdio.h>
#include <math.h>
int count(long long int n, int factor)
{
    int count = 0;
    while (n % factor == 0)
    {
        count++;
        n /= factor;
    }
    return count;
}
int main()
{
    int n;
    long long int a;
    int c_5, c_2, times;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lld", &a);
        c_5 = count(a, 5);
        c_2 = count(a, 2);
        times = 0;
        if (c_5 > c_2)
        {
            times = c_5 - c_2;
            times = ceil((float)times / 2);
        }
        printf("%lld\n", a * (1 << (2 * times)));
        //printf("5-count = %d\n2-count = %d\ntimes = %d\nMultiplier = %d\n", c_5, c_2, times, 1 << (2 * times));
    }
    return 0;
}