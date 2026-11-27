#include <stdio.h>
int main(){
    int a;
    for(a = 33;a <= 126;a++){
        printf("ascii character for %3d is %c\n",a,a);
    }
    return 0;
}