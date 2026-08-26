#include <stdio.h>
int factorial(int num){int a,b,c = 1;
    for(b = num;b != 1;b--){
        c = c * b;
    }
    return c;
}
int main(){
    int d;
    float e,f = 0,g,h;
   printf("give num of terms: ");
   scanf("%d", &d);
   for(float i = 1;i <= d;i++){
    g = factorial(i);
    e = i / g;
    f = f + e;
   }
   printf("%f",f);
    
}