#include <stdio.h>
int main(){
    int a,b,c,d = 1,e = 0,f;
    printf("give a binary code: ");
    scanf("%d", &a);
    b = a;
    while(b > 0){
        c = b % 10;
        c = c * d;
        d = d * 2;
        e = e + c;
        b = b / 10;

    }
    printf("The integer corresponding to your binary code %d is %d",a,e);

}