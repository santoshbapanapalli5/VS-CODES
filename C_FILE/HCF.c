#include <stdio.h>
#include <stdlib.h>
int main(){
    system("cls");
    int a,b,c,d;
    printf("give first num: ");
    scanf("%d", &a);
    printf("give second num: ");
    scanf("%d", &b);
    if(a < b){
        for(c = a;c >= 1;c--){
            if(a % c == 0 && b % c == 0){
                printf("hcf is %d",c);
                break;
            }
        }
    }
    else if(b < a){
        for(c = b;c >= 1;c--){
            if(a % c == 0 && b % c == 0){
                printf("hcf is %d",c);
                break;
            }
        }
    }
    else if ( a == b){
        for(c = a;c >= 1;c--){
            if(a % c == 0 && b % c == 0){
                printf("hcf is %d",c);
                break;
            }
        }
    }
    return 0;
}