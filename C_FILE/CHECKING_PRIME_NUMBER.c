#include <stdio.h>

int main()
{
    int a,b,i;
    printf("give a num: ");
    scanf("%d", &a);
    if(a <= 0){
        printf("error");
    }
    else{
        for(i = 2;i < a;i++){
        if(a % i == 0){
            break;
        }
        }
    if(a == i){
        printf("prime");
    }
    else{
        printf("not prime");
    }
    }
    return 0;
}