#include <stdio.h>
int main() {
    int a,b,c,d,e,f;
    printf("which table do you want to print: ");
    scanf("%d", &a);
    printf("upto how many terms do you want this %d table: ",a);
    scanf("%d", &b);
    for(c = 1;c <= b;c++){
        printf("%3d   *   %3d   =   %3d\n",a,c,d = a*c);
    }
    return 0;
}
