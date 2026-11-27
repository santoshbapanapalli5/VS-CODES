#include <stdio.h>

int main()
{
    int d[5];
    printf("give 1st num: ");
    scanf("%d", &d[0]);
    printf("give 2nd num: ");
    scanf("%d", &d[1]);
    printf("give 3rd num: ");
    scanf("%d", &d[2]);
    printf("give 4th num: ");
    scanf("%d", &d[3]);
    printf("give 5th num: ");
    scanf("%d", &d[4]);
    if(d[0] >= d[1] && d[0] >= d[2] && d[0] >= d[3] && d[0] >= d[4]){
        printf("max is %d",d[0]);
    } 
    else if(d[1] >= d[2] && d[1] >= d[3] && d[1] >= d[4])    {
        printf("max is %d",d[1]);
    }
    else if(d[2] >= d[3] && d[2] >= d[4]){
        printf("max is %d",d[2]);
    }
    else if(d[3] >= d[4]){
        printf("max is %d",d[3]);
    }
    else{
        printf("max is %d",d[4]);
    }
    return 0;
}