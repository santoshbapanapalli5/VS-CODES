#include <stdio.h>
#include <math.h>
#include <windows.h>
int main(){
    SetConsoleOutputCP(65001);
    double a,b,c,d,e;
    printf("give the corresponding values for aX² + bX + c\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);
    d =( -b + sqrt(b*b - 4*a*c) )/(2*a);
    e =( -b - sqrt(b*b - 4*a*c) )/(2*a);
    if(d == e){
        printf("the equation has equal roots and it is %.2lf",d);
    }
    else{
        printf("the roots of the given equation are %.2lf and %.2lf",d,e);
    }
    return 0;
}