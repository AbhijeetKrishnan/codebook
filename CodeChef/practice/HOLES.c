#include <stdio.h>
int main()
{
    int t;
    char input[100];
    scanf("%d", &t);
    while (t--)
    {
        int holes = 0;
        int i = 0;
        scanf("%s", input);
        while (input[i] != '\0')
        {
            if ((input[i] == 'A') || (input[i] == 'D') || (input[i] == 'O') || (input[i] == 'P') || (input[i] == 'Q') || (input[i] == 'R'))
            {
                holes += 1;
            }
            else if (input[i] == 'B')
            {
                holes += 2;
            }
            i++;
        }
        printf("%d\n", holes);
    }
    return 0;
}