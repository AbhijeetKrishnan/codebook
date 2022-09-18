#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100000
int main()
{
    int t;
    char chain[MAX_SIZE], correct_chain_1[MAX_SIZE], correct_chain_2[MAX_SIZE];
    int count_1, count_2;
    int length, i;
    scanf("%d", &t);
    while(t--)
    {
        count_1 = 0;
        count_2 = 0;
        scanf("%s", chain);
        length = strlen(chain);
        for (i = 0; i < length; i++)
        {
            if (i % 2 == 0)
            {
                correct_chain_1[i] = '-';
                correct_chain_2[i] = '+';
            }
            else
            {
                correct_chain_1[i] = '+';
                correct_chain_2[i] = '-';
            }
        }
        //printf("%s\n", correct_chain_1);
        //printf("%s\n", correct_chain_2);
        for (i = 0; i < length; i++)
        {
            if (chain[i] != correct_chain_1[i])
            {
                count_1++;
            }
            if (chain[i] != correct_chain_2[i])
            {
                count_2++;
            }
        }
        if (count_1 < count_2)
        {
            printf("%d\n", count_1);
        }
        else
        {
            printf("%d\n", count_2);
        }
    }
    return 0;
}