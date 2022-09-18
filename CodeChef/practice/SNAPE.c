#include <stdio.h>
#include <math.h>
//#define ERROR 0.01

/*float abs (float input)
{
    if (input > 0)
    {
        return input;
    }
    else
    {
        return (-(input));
    }
}
float sqrt(int input)
{
    float guess1, guess2;
    guess1 = input / 2;
    do
    {
        guess2 = input / guess1;
        guess1 = (guess1 + guess2) / 2;
    }while (abs(guess1 - guess2) >= ERROR);
}
*/
int main()
{
    int T;
    int B, LS;
    float min, max;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &B, &LS);
        max = sqrt((LS * LS) + (B * B));
        min = sqrt((LS * LS) - (B * B));
        printf("%f %f\n", min, max);
    }
    return 0;
}