#include <stdio.h>
int main(){
    int a,b,c,d = 1,e = 0,f,g;
    printf("give a number: ");
    scanf("%d", &a);
    c = a;
    f = a;
    while (a > 0)
    {
        b = c % 2;
        c = c / 2;
        a = c;
        b = b * d;
        e = e + b;
        d = d * 10;
    }
    printf("The binary code corresponding to your integer %d is %d",f,e);
    return 0;
}