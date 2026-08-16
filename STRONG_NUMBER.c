#include <stdio.h>

int factorial(int a)
{
    int b, c = 1;
    for (b = a; b > 1; b--)
    {
        c = c * b;
    }
    return c;
}

int main()
{
    int a, b, c = 0, d[10], e = 0, f;

    printf("give a number to check is it strong number: ");
    scanf("%d", &a);

    b = a;
    for (f = 0; b != 0; f++)
    {
        d[f] = b % 10;
        b = b / 10;
        c++;
    }

    for (f = 0; f < c; f++)
    {
        e = e + factorial(d[f]);
    }

    printf("Sum of factorials: %d\n", e);

    if (e == a)
    {
        printf("%d is a Strong Number", a);
    }
    else
    {
        printf("%d is not a Strong Number", a);
    }

    return 0;
}