#include <stdio.h>
int abs(int n)
{
    if (n > 0)
    {
        return n;
    }
    else
    {
        return -n;
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    int S, T;
    int cumul_S = 0, cumul_T = 0;
    int max_lead = 0;
    int lead;
    while (N--)
    {
        scanf("%d %d", &S, &T);
        cumul_S += S;
        cumul_T += T;
        lead = cumul_S - cumul_T;
        if (abs(lead) > abs(max_lead))
        {
            max_lead = lead;
        }
    }
    if (max_lead > 0)
    {
        printf("1 %d\n", max_lead);
    }
    else
    {
        printf("2 %d\n", abs(max_lead));
    }
    return 0;
}