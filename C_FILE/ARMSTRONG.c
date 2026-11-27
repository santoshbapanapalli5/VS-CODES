#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c, d, f = 0, g, i;
    printf("give a number to check is it armstrong number: ");
    scanf("%d", &a);
    b = a;
    int count = 0;
    int digits[100];
    for (c = 0; b != 0; c++)
    {
        d = b % 10;
        digits[c] = d;
        b = b / 10;
        count++;
    }
    double e;
    for (i = 0; i < count; i++)
    {
        e = pow(digits[i], count);
        f = f + e;
    }
    if (a == f)
    {
        printf("%d is a armstrong number", a);
    }
    else
    {
        printf("%d is not a armstrong number", a);
    }

    return 0;
}