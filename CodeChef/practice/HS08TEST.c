#include <stdio.h>

int main()
{
    int withdraw_amt;
    float bank_bal;
    scanf("%d %f", &withdraw_amt, &bank_bal);
    if (withdraw_amt == 0)
    {
        printf("%.2f\n", bank_bal);
    }
    else if ((withdraw_amt % 5 == 0) && (bank_bal >= withdraw_amt + 0.50))
    {
        printf("%.2f\n", (bank_bal - withdraw_amt - 0.50));
    }
    else
    {
        printf("%.2f\n", bank_bal);
    }
    return 0;
}