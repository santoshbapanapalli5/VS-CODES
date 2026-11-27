#include <stdio.h>

int main()
{
    int a,b,c,d,e,f,g,h;
    printf("give num of rows: ");
    scanf("%d", &a);
    for(b = 1;b <= a;b++){
        for(c = 1;c <= a - b;c++){
            printf(" ");
        }
        for(d = 1;d <= b;d++){
            printf("%d ",d);
        }
        printf("\n");
    }

    return 0;
}