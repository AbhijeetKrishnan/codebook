#include <stdio.h>

int main()
{
    int A, B;
    int result;
    scanf("%d %d", &A, &B);
    result = A - B;
    //printf("%d\n", result);
    if ((result % 10) == 9)
    {
        printf("%d\n", (result - 1));
    }
    else
    {
        printf("%d\n", (result + 1));
    }
    //printf("%d\n", ((A - B) ^ 1));
    return 0;
}