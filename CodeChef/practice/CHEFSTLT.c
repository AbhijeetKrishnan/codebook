#include <stdio.h>
int main()
{
    int t;
    char s1[101], s2[101];
    scanf("%d", &t);
    int i;
    int soft_diff, hard_diff;
    while (t--)
    {
        scanf("%s", s1);
        scanf("%s", s2);
        soft_diff = 0;
        hard_diff = 0;
        for (i = 0; s1[i] != '\0'; i++)
        {
            if ((s1[i] == '?') || (s2[i] == '?'))
            {
                soft_diff++;
            }
            else if (s1[i] != s2[i])
            {
                hard_diff++;
            }
        }
        printf("%d %d\n", hard_diff, hard_diff + soft_diff);
    }
    return 0;
}