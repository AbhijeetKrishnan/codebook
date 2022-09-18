#include <stdio.h>

int main()
{
    unsigned int T;
    unsigned int N;
    unsigned int five_count;
    unsigned int five_power;
    unsigned int inc_five;
    scanf("%lu", &T);
    while (T--)
    {
        scanf ("%lu", &N);
        five_count = 0;
        five_power = 5;
        inc_five = N / 5;
        while (inc_five > 0)
        {
            five_count += inc_five;
            five_power *= 5;
            inc_five = N / five_power;
        }
        printf("%lu\n", five_count);
    }
    return 0;
}