#include <stdio.h>

int main()
{
    int input;
    scanf("%d", &input);
    while (input != 42)
    {
        printf("%d\n", input);
        scanf("%d", &input);
    }
    return 0;
}