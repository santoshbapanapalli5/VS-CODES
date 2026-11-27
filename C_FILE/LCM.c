#include <stdio.h>

int main()
{
    int a,b,c,step;
    printf("give two num: ");
    scanf("%d", &a);
    scanf("%d", &b);
    step = (a > b) ? a : b;
    for(c = step; ; c += 1){
        if(c % a == 0 && c % b == 0){
            printf("lcm is %d",c);
            break;
        }
    }
    return 0;
}