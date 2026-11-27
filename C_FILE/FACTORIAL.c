#include <stdio.h>
int main(){
    int a,b,c = 1,d;
    printf("give: ");
    scanf("%d", &a);
    for(b = a;b != 1;b--){
        c = c * b;
    }
    printf("%d",c);
    return 0;
}