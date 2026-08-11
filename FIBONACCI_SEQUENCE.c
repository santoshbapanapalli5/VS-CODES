#include <stdio.h>

int main()
{
    long long a,b,c,d,i;
    a = 0;
    b = 1;
    printf("no.of terms: ");
    scanf("%lld", &c);
    for(i = 1;i <= c;i++){
        printf("%lld  ",a);
        d = a + b;
        a = b;
        b = d;
    }
    return 0;
}