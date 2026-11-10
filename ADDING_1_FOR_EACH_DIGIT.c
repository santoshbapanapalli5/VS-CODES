#include <stdio.h>
int main()
{
    int a, b, c = 0, d, e = 1;
    printf("Enter 5 digit number: ");
    scanf("%d", &a);
    b = a;
    while (b != 0)
    {
        d = b % 10;
        d = (d + 1) % 10;
        c = c + d * e;
        e = e * 10;
        b = b / 10;
    }
    printf("%d", c);
    return 0;
}
