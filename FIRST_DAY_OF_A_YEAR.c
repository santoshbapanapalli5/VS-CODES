#include <stdio.h>
int main()
{
    int a, b, c = 0, d, e, f;
    printf("give year: ");
    scanf("%d", &a);
    for (d = 0; d < a; d++)
    {
        if ((d % 4 == 0 && d % 100 != 0) || d % 400 == 0)
        {
            for (b = 0; b < 366; b++)
            {
                c = c + 1;
                c = c % 7;
            }
        }
        else
        {
            for (b = 0; b < 365; b++)
            {
                c = c + 1;
                c = c % 7;
            }
        }
    }
    if (c == 1)
    {
        printf("sun");
    }
    if (c == 2)
    {
        printf("mon");
    }
    if (c == 3)
    {
        printf("tue");
    }
    if (c == 4)
    {
        printf("wed");
    }
    if (c == 5)
    {
        printf("thu");
    }
    if (c == 6)
    {
        printf("fri");
    }
    if (c == 7)
    {
        printf("sat");
    }

    return 0;
}