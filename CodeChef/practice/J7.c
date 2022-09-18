#include <stdio.h>
#define ERROR 0.0001
float myabs (float input)
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
float mysqrt(float input)
{
    float guess1, guess2;
    guess1 = input / 2.0;
    do
    {
        guess2 = input / guess1;
        guess1 = (guess1 + guess2) / 2;
    }while (myabs(guess1 - guess2) >= ERROR);
    return guess1;
}
int main()
{
    unsigned int T;
    unsigned int P, S;
    float side1, side2;
    float side1_square, side2_square;
    float volume1, volume2;
    float discriminant;
    scanf("%u", &T);
    while (T--)
    {
        scanf ("%u %u", &P, &S);
        discriminant = mysqrt(P * P - 24 * S);
        side1 = (P + discriminant) / 12;
        side2 = (P - discriminant) / 12;
        side1_square = side1 * side1;
        side2_square = side2 * side2;
        volume1 = side1_square * side1 - (P / 4) * side1_square + (S / 2) * side1;
        volume2 = side2_square * side2 - (P / 4) * side2_square + (S / 2) * side2;
        printf("%.2f\n", ((volume1 > volume1)? volume1 : volume2));
    }
    return 0;
}